

#ifndef ACTISHA2_64_H
#define ACTISHA2_64_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) actSHA384Init(VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA512Init(VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Init(VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Init(VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA384Update(
  VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512Update(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Update(
  VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Update(
  VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA384Finalize(
  VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
  }
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

