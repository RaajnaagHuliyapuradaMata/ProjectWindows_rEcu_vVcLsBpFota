

#define ESLIB_AES128ENC_SOURCE

#include "ESLib_AES_common.hpp"

#if(VSECPRIM_AES128_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode, VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector){
  actU8 targetMode = actPADDING_PM_OFF;
  eslt_ErrorCode retVal = esl_AES_CommonInit(&targetMode, workSpace, ESL_MINSIZEOF_WS_AES128, key, blockMode, paddingMode);

  if(retVal == ESL_ERC_NO_ERROR){
    if(actOK == actAESInitEncrypt(&workSpace->wsAES, key, ESL_SIZEOF_AES128_KEY, initializationVector, targetMode, workSpace->header.watchdog)){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_AES128);
    }
    else{
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace
   ,                                               const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  eslt_ErrorCode retVal = esl_AES_CommonProcChecks(workSpace, ESL_WST_ALGO_AES128, ESL_MAXSIZEOF_WS_AES128, input, output);

  if(retVal != ESL_ERC_NO_ERROR){
  }
  else if(outputSize == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    actRETURNCODE result;
    actLengthType enc_len = *outputSize;

    result = actAESEncrypt(&workSpace->wsAES, input, (actLengthType)inputSize, output, &enc_len, FALSE, workSpace->header.watchdog);

    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length) enc_len;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (outputSize == NULL_PTR) || (output == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_AES128, ESL_WST_ALGO_AES128)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE result;
    actLengthType enc_len = (actLengthType) *outputSize;

    result = actAESEncrypt(&workSpace->wsAES, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, 0, output, &enc_len, TRUE, workSpace->header.watchdog);

    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)enc_len;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAES);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES128Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal = esl_AES_CommonInitChecks(workSpace, sizeof(workSpace->wsAES.e_key), key);

  if(retVal == ESL_ERC_NO_ERROR){
    if(actOK == actAESInitEncryptBlock(&workSpace->wsAES, key, ESL_SIZEOF_AES128_KEY, workSpace->header.watchdog)){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_AES128);
    }
    else{
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES128Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock){
  eslt_ErrorCode retVal = esl_AES_CommonProcChecks(workSpace, ESL_WST_ALGO_AES128, sizeof(workSpace->wsAES.e_key), inputBlock, outputBlock);

  if(retVal == ESL_ERC_NO_ERROR){
    actAESEncryptBlock(&workSpace->wsAES, inputBlock, outputBlock, workSpace->header.watchdog);
  }
  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

