

#define ESLIB_RSA_V15_SIG_RIPEMD160_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_ASN_1.hpp"

#include "actIRSA.hpp"
#include "actIRMD160.hpp"

#if(VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON)

#define ESL_RSA_V15_INIT_HASH_FCT(workspace)                         (void)actRMD160Init(&((workspace)->wsRIPEMD160))

#define ESL_RSA_V15_UPDATE_HASH_FCT(workspace, inputSize, input)     actRMD160Update(&((workspace)->wsRIPEMD160), (VSECPRIM_P2CONST_PARA(actU8))(input), (inputSize),  (workspace)->header.watchdog)

#define ESL_RSA_V15_FINALIZE_HASH_FCT(workspace, messageDigest)      (void)actRMD160Finalize(&((workspace)->wsRIPEMD160), (VSECPRIM_P2VAR_PARA(actU8))(messageDigest), (workspace)->header.watchdog)

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, eslt_Byte) eslt_SIGN_RSA_RIPEMD160_V15_ASN1_DIGESTINFO[] = ASN1_DIGESTINFO_RIPEMD160;

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,                                                          eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_SIG){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      if(keyPairModuleSize < ASN1_MINIMAL_SIGVER_KEY_LENGTH)
      {
        returnValue = ESL_ERC_RSA_MODULE_OUT_OF_RANGE;
      }
      else
      {
        workSpace->wsHashUnion.RIPEMD160ws.header.size = ESL_MAXSIZEOF_WS_RIPEMD160;
        workSpace->wsHashUnion.RIPEMD160ws.header.watchdog = workSpace->header.watchdog;
        ESL_RSA_V15_INIT_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws));
        workSpace->wsRSASigPrim.header.size = ESL_MAXSIZEOF_WS_RSA_PRIM;
        workSpace->wsRSASigPrim.header.watchdog = workSpace->header.watchdog;
        returnValue = esl_initSignRSA_prim(&(workSpace->wsRSASigPrim), keyPairModuleSize, keyPairModule, privateKeyExponentSize, privateKeyExponent);
      }
    }
    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace, eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(ESL_WST_ALGO_RSA != (workSpace->header.status & ESL_WST_M_ALGO)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else if(0u == (workSpace->header.status & ESL_WST_M_RUNNING)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else{
      if(actOK != ESL_RSA_V15_UPDATE_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws), inputSize, input))
      {
        returnValue = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
      }
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,                                                              VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize, i, padBytesNeeded;
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageBuf;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    i = 0u;

    keyPairModuleSize = workSpace->modulusSizeInformation;
    messageBuf = workSpace->messageBuffer;

    if(ESL_WST_ALGO_RSA != (workSpace->header.status & ESL_WST_M_ALGO)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else if(0u == (workSpace->header.status & ESL_WST_M_RUNNING)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else{
      messageBuf[i] = 0x00u;
      messageBuf[i + 1u] = 0x01u;
      i += 2u;

      padBytesNeeded = keyPairModuleSize - ASN1_SIZEOF_PARAMETERS_WITH_FIXED_LENGTH;

      actMemset((VSECPRIM_P2VAR_PARA(actU8)) (&messageBuf[i]), 0xFFu, padBytesNeeded);
      i = padBytesNeeded + i;
      messageBuf[i] = 0x00u;
      i += 1u;
      actMemCpyByteArray((VSECPRIM_P2VAR_PARA(actU8)) (&messageBuf[i]), eslt_SIGN_RSA_RIPEMD160_V15_ASN1_DIGESTINFO, sizeof(eslt_SIGN_RSA_RIPEMD160_V15_ASN1_DIGESTINFO));
      i += ((eslt_Length) sizeof(eslt_SIGN_RSA_RIPEMD160_V15_ASN1_DIGESTINFO));
      ESL_RSA_V15_FINALIZE_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws), &messageBuf[i]);

      returnValue = esl_signRSA_prim(&(workSpace->wsRSASigPrim), keyPairModuleSize, messageBuf, signatureSize, signature);
    }
  }
  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

