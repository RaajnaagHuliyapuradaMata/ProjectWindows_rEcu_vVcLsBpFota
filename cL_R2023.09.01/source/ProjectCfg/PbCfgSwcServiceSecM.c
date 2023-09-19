#define SECMPAR_SOURCE

#include "Sec.hpp"
#include "SwcServiceCsm.hpp"

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_AesKey[2]              = {{AesKeyKey,              16u, 1u},   {AesKeyIV,  16u, 5u}};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_ClassCCC_Ed25519Key[1] = {{ClassCCC_Ed25519Key,    32u, 1u}};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_ClassC_Key[1]          = {{ClassC_Key,             16u, 1u}};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_ClassCCC_Rsa1024Key[2] = {{ClassCCC_Rsa1024KeyExp, 4u,  161u}, {ClassCCC_Rsa1024KeyMod, 128u, 160u}};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_ClassCCC_Rsa2048Key[2] = {{ClassCCC_Rsa2048KeyExp, 4u,  161u}, {ClassCCC_Rsa2048KeyMod, 256u, 160u}};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_ClassCCC_Rsa3072Key[2] = {{ClassCCC_Rsa3072KeyExp, 4u,  161u}, {ClassCCC_Rsa3072KeyMod, 384u, 160u}};

V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassDDDConfig[1] = {{SecM_VerifyClass_DDD, SEC_SIZE_CHECKSUM_CRC_32, 0x00000000u,  SEC_UPDATE_OPERATION_VERIFICATION}};
V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassCConfig[1]   = {{SecM_Verify_ClassC,   SEC_SIZE_HASH_SHA1,       0x00000000u,  (SEC_UPDATE_OPERATION_VERIFICATION | SEC_UPDATE_OPERATION_ADDRESS_LENGTH)}};
V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassCCCConfig[1] = {{SecM_VerifyClass_CCC, SEC_SIZE_SIG_RSA2048,     0x00000000u,  SEC_UPDATE_OPERATION_VERIFICATION}};
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"



#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 AesKeyKey[16]               = {0x00u, 0x11u, 0x22u, 0x33u, 0x44u, 0x55u, 0x66u, 0x77u, 0x88u, 0x99u, 0xAAu, 0xBBu, 0xCCu, 0xDDu, 0xEEu, 0xFFu};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 AesKeyIV[16]                = {0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Ed25519Key[32]     = {0x6Fu, 0x09u, 0x87u, 0x67u, 0x65u, 0x25u, 0xDFu, 0xD7u, 0xB7u, 0xCCu, 0x1Au, 0x73u, 0x63u, 0x19u, 0x0Du, 0xC1u, 0x36u, 0xD7u, 0xFAu, 0xE7u, 0xDCu, 0x39u, 0xE1u, 0x8Au, 0xFFu, 0xFCu, 0x74u, 0x48u, 0x4Bu, 0x05u, 0x73u, 0x4Au};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassC_Key[16]              = {0x00u, 0x11u, 0x22u, 0x33u, 0x44u, 0x55u, 0x66u, 0x77u, 0x88u, 0x99u, 0xAAu, 0xBBu, 0xCCu, 0xDDu, 0xEEu, 0xFFu};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa1024KeyExp[4]   = {0x00u, 0x00u, 0x9Du, 0x85u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa1024KeyMod[128] = {0xF7u, 0x24u, 0x2Fu, 0x3Bu, 0xB8u, 0x69u, 0x7Eu, 0xE5u, 0xC3u, 0xACu, 0xAFu, 0x80u, 0x0Bu, 0xA1u, 0xC8u, 0x4Eu, 0x3Cu, 0x89u, 0xEAu, 0x37u, 0x39u, 0x87u, 0x07u, 0x3Du, 0x97u, 0x1Eu, 0x91u, 0xF8u, 0x3Au, 0xD4u, 0x36u, 0xF6u, 0x09u, 0xBBu, 0xBBu, 0x8Fu, 0xBFu, 0x25u, 0x03u, 0x98u, 0x86u, 0x0Bu, 0xB2u, 0x0Cu, 0x63u, 0x0Bu, 0xA1u, 0x24u, 0xD9u, 0x34u, 0x8Bu, 0xE0u, 0xBAu, 0x61u, 0xF9u, 0x43u, 0x66u, 0x21u, 0x20u, 0x5Eu, 0x02u, 0x89u, 0xAEu, 0x23u, 0x8Du, 0xDAu, 0xBDu, 0x16u, 0xEBu, 0xB7u, 0x15u, 0xEAu, 0x85u, 0xDDu, 0xB9u, 0x88u, 0xCCu, 0x31u, 0xD3u, 0x74u, 0xD7u, 0xC5u, 0x80u, 0x0Au, 0x74u, 0xF6u, 0xDAu, 0x68u, 0x11u, 0x06u, 0xD0u, 0xA6u, 0x3Du, 0x50u, 0xBAu, 0x1Fu, 0xEAu, 0x4Fu, 0xC2u, 0x02u, 0x95u, 0x0Fu, 0x58u, 0x2Eu, 0x12u, 0xE0u, 0xBAu, 0xF6u, 0xFFu, 0xE0u, 0xF4u, 0xC5u, 0xE2u, 0x76u, 0xA5u, 0xAAu, 0xDAu, 0xE7u, 0xB8u, 0x77u, 0x34u, 0x76u, 0xD0u, 0x9Bu, 0x0Bu, 0x88u, 0x3Au, 0x83u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa2048KeyExp[4]   = {0x00u, 0x01u, 0x00u, 0x01u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa2048KeyMod[256] = {0xB1u, 0xC5u, 0xBEu, 0x46u, 0x9Au, 0x4Fu, 0x56u, 0x09u, 0x8Bu, 0x1Bu, 0x4Eu, 0xC0u, 0xB5u, 0x15u, 0x02u, 0xB0u, 0xE8u, 0x9Cu, 0x14u, 0x7Au, 0x8Fu, 0x76u, 0x97u, 0x08u, 0x07u, 0x8Du, 0x3Au, 0xA3u, 0x95u, 0xECu, 0x97u, 0xCDu, 0x76u, 0x84u, 0x8Cu, 0x9Du, 0x9Au, 0x6Eu, 0x00u, 0xC3u, 0xF2u, 0xC1u, 0xCBu, 0xE3u, 0x5Au, 0xA5u, 0xFFu, 0xD9u, 0xC0u, 0x6Cu, 0xAAu, 0xFDu, 0xE1u, 0x6Au, 0x61u, 0xBFu, 0x06u, 0xE4u, 0x15u, 0xBDu, 0xA6u, 0xD5u, 0x2Bu, 0x57u, 0x37u, 0x18u, 0x8Bu, 0x01u, 0xB6u, 0x09u, 0x29u, 0x2Fu, 0x08u, 0xAFu, 0x97u, 0x60u, 0xEDu, 0x62u, 0x31u, 0x6Eu, 0x00u, 0x66u, 0x55u, 0x63u, 0x1Au, 0x7Eu, 0xF9u, 0xB2u, 0x3Du, 0xBDu, 0xD4u, 0xA5u, 0xF4u, 0xF6u, 0xF6u, 0xC8u, 0x7Bu, 0x65u, 0x75u, 0xDCu, 0x40u, 0xD0u, 0x5Eu, 0x75u, 0x45u, 0x1Du, 0xD3u, 0x94u, 0x58u, 0x3Du, 0x89u, 0xC9u, 0x23u, 0x80u, 0xAFu, 0xB5u, 0x98u, 0xC7u, 0x75u, 0x64u, 0xD1u, 0x35u, 0x28u, 0x1Cu, 0xA6u, 0x9Bu, 0x72u, 0x5Cu, 0xD2u, 0x72u, 0xDAu, 0xB4u, 0x78u, 0xFEu, 0x33u, 0x0Du, 0xF9u, 0xD3u, 0x13u, 0x6Du, 0x57u, 0x59u, 0x7Fu, 0x7Fu, 0x40u, 0xE9u, 0x65u, 0xEDu, 0xF3u, 0x27u, 0xC7u, 0x29u, 0x86u, 0xD8u, 0x02u, 0x86u, 0x06u, 0x3Cu, 0xC9u, 0xAAu, 0x16u, 0x5Bu, 0xBDu, 0xCEu, 0x00u, 0xDCu, 0x0Eu, 0x67u, 0x44u, 0x5Au, 0x62u, 0x55u, 0x4Du, 0x66u, 0xC7u, 0x57u, 0x75u, 0x17u, 0x4Fu, 0x57u, 0x5Cu, 0xA9u, 0xE2u, 0xF6u, 0x48u, 0xEBu, 0xA9u, 0x7Fu, 0x0Bu, 0x26u, 0x1Bu, 0xA6u, 0xDFu, 0x91u, 0x8Cu, 0x53u, 0x5Cu, 0x04u, 0x30u, 0xAFu, 0x04u, 0x5Bu, 0xADu, 0x7Fu, 0x41u, 0xBEu, 0x01u, 0xEEu, 0x8Fu, 0x89u, 0x18u, 0x25u, 0xD5u, 0x41u, 0x43u, 0x4Du, 0x8Fu, 0x42u, 0x9Fu, 0xA7u, 0x4Fu, 0xACu, 0x7Au, 0xF4u, 0xA0u, 0x0Du, 0x95u, 0xF0u, 0x7Du, 0x1Cu, 0x7Fu, 0x5Du, 0xFAu, 0xE9u, 0x4Au, 0x46u, 0x8Cu, 0xD5u, 0x35u, 0x1Eu, 0x1Bu, 0x0Cu, 0x15u, 0xE9u, 0xF5u, 0x2Fu, 0xA8u, 0xF1u, 0x01u, 0xB1u, 0x7Cu, 0xF7u, 0x84u, 0x63u, 0x2Du, 0x75u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa3072KeyExp[4]   = {0x00u, 0x01u, 0x00u, 0x01u};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 ClassCCC_Rsa3072KeyMod[384] = {0xD2u, 0x7Du, 0xA6u, 0x5Au, 0xF1u, 0xBEu, 0x1Bu, 0x29u, 0x38u, 0x25u, 0x8Au, 0xC8u, 0x5Eu, 0xA5u, 0xABu, 0xBCu, 0xBEu, 0x39u, 0x29u, 0x69u, 0x23u, 0x56u, 0x27u, 0x64u, 0xF6u, 0x5Eu, 0xB0u, 0x17u, 0x99u, 0x8Du, 0x17u, 0x10u, 0x5Du, 0xF6u, 0x2Du, 0x9Du, 0x80u, 0x70u, 0xF4u, 0x46u, 0x22u, 0xBBu, 0x74u, 0x88u, 0xD1u, 0x9Fu, 0x65u, 0xA6u, 0xEFu, 0x82u, 0x9Fu, 0xD5u, 0x9Cu, 0xF0u, 0x2Au, 0x70u, 0x2Cu, 0x32u, 0x16u, 0xC0u, 0x97u, 0xBEu, 0xD8u, 0x66u, 0x65u, 0xFEu, 0x92u, 0x52u, 0x79u, 0x79u, 0x82u, 0xB9u, 0xFEu, 0x2Fu, 0x16u, 0x8Au, 0x23u, 0xEAu, 0x16u, 0xAAu, 0x7Du, 0xEFu, 0x98u, 0xE1u, 0xDCu, 0x0Au, 0x75u, 0xDBu, 0x23u, 0xEDu, 0x62u, 0x5Fu, 0x50u, 0x64u, 0x78u, 0xD1u, 0x87u, 0x98u, 0x87u, 0xA4u, 0x0Bu, 0x8Cu, 0x76u, 0x2Eu, 0x6Eu, 0x76u, 0x93u, 0xE7u, 0x0Bu, 0x46u, 0x42u, 0xF8u, 0x63u, 0x59u, 0x48u, 0x42u, 0xDEu, 0x66u, 0x53u, 0x9Au, 0xBAu, 0x12u, 0xB8u, 0x0Eu, 0xBDu, 0xA1u, 0x9Du, 0x99u, 0xD9u, 0x4Fu, 0x9Eu, 0xC6u, 0xA1u, 0x8Eu, 0x9Eu, 0xDCu, 0x2Eu, 0xAFu, 0x38u, 0x1Du, 0x6Au, 0x69u, 0x5Du, 0xF4u, 0x9Eu, 0x30u, 0x06u, 0xEBu, 0x2Fu, 0x73u, 0x94u, 0x67u, 0xBAu, 0x5Du, 0x34u, 0x07u, 0x0Eu, 0x95u, 0xDCu, 0x61u, 0x8Bu, 0xA7u, 0x12u, 0xD8u, 0x16u, 0xC4u, 0x7Au, 0x0Du, 0x24u, 0x70u, 0xB7u, 0x18u, 0x9Au, 0xCCu, 0x40u, 0x3Fu, 0xC6u, 0xE2u, 0x57u, 0x2Cu, 0xADu, 0x7Eu, 0x1Eu, 0x40u, 0xDEu, 0x71u, 0x58u, 0x58u, 0x6Eu, 0xF3u, 0x4Au, 0x80u, 0x6Du, 0x25u, 0x28u, 0xBDu, 0x48u, 0x1Bu, 0x30u, 0xE7u, 0x9Du, 0x43u, 0x00u, 0x52u, 0x10u, 0x3Bu, 0xE5u, 0xA4u, 0x4Cu, 0x31u, 0xC3u, 0xE4u, 0xEBu, 0xF2u, 0x37u, 0x08u, 0xFAu, 0x4Fu, 0x04u, 0x28u, 0xC9u, 0xFDu, 0x14u, 0x42u, 0x90u, 0x14u, 0xCBu, 0x64u, 0x86u, 0x00u, 0x8Bu, 0x44u, 0xA2u, 0xA8u, 0xA1u, 0xCCu, 0x14u, 0x62u, 0x96u, 0xAAu, 0x99u, 0xCCu, 0x2Eu, 0x7Bu, 0x4Du, 0x3Cu, 0xF7u, 0x8Eu, 0x71u, 0x03u, 0x37u, 0x98u, 0x90u, 0x54u, 0x5Fu, 0xF1u, 0x05u, 0xCEu, 0x50u, 0xE8u, 0x2Au, 0xC5u, 0xFEu, 0xF0u, 0xA5u, 0xDFu, 0x43u, 0xCBu, 0x34u, 0x62u, 0x54u, 0x27u, 0xBAu, 0x57u, 0xE7u, 0xF1u, 0x74u, 0xBCu, 0x1Eu, 0x3Au, 0xDAu, 0x54u, 0xD5u, 0xF0u, 0x2Bu, 0x8Au, 0x7Eu, 0xBDu, 0xDBu, 0x13u, 0xC8u, 0x8Au, 0x91u, 0xC1u, 0xF8u, 0xFAu, 0xFDu, 0xDBu, 0x0Cu, 0x67u, 0xF1u, 0x70u, 0x05u, 0x19u, 0x4Au, 0x78u, 0x49u, 0xAFu, 0xD9u, 0x14u, 0x91u, 0x15u, 0xA5u, 0x29u, 0xF8u, 0x82u, 0xD1u, 0x64u, 0x29u, 0xACu, 0x07u, 0xF2u, 0x16u, 0xB5u, 0x64u, 0x8Eu, 0xBCu, 0xEBu, 0x07u, 0xADu, 0xEEu, 0x0Fu, 0xE5u, 0x32u, 0x37u, 0xBBu, 0xE9u, 0x22u, 0x4Au, 0x9Du, 0x21u, 0xB3u, 0x53u, 0xC1u, 0x5Au, 0x2Fu, 0x03u, 0xF4u, 0x54u, 0xF9u, 0x02u, 0xCEu, 0x18u, 0xD8u, 0x9Fu, 0x3Bu, 0x4Cu, 0x64u, 0x18u, 0x6Fu, 0xC4u, 0x1Du, 0x9Fu, 0xB2u, 0xD2u, 0xDBu, 0x1Fu, 0x42u, 0x5Au, 0x8Cu, 0xDBu, 0x7Du, 0x90u, 0x93u, 0x80u, 0x0Au, 0x0Bu, 0xBDu, 0x36u, 0x39u, 0x97u, 0x5Bu, 0xD1u, 0xFFu};

V_MEMROM0 V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 SecM_CryptographicKeys[6] = {
      {2u, SecM_KeyValueList_AesKey}
   ,  {1u, SecM_KeyValueList_ClassCCC_Ed25519Key}
   ,  {1u, SecM_KeyValueList_ClassC_Key}
   ,  {2u, SecM_KeyValueList_ClassCCC_Rsa1024Key}
   ,  {2u, SecM_KeyValueList_ClassCCC_Rsa2048Key}
   ,  {2u, SecM_KeyValueList_ClassCCC_Rsa3072Key}
};

V_MEMROM0 V_MEMROM1 SecM_DecPrimitiveType V_MEMROM2 SecM_DecryptionPrimitives[1] = {
   {SecM_DecryptionJob, SmhConf_SmhJob_SmhJob_AesDecryption}
};

V_MEMROM0 V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 SecM_CrcPrimitives[1] = {
   {
         SEC_CRC32
      ,  (SecM_CRCFunctionGenericType)SecM_ComputeCrc32
      ,  SEC_SIZE_CHECKSUM_CRC_32
      ,  FALSE
      ,  FALSE
   }
};

V_MEMROM0 V_MEMROM1 SecM_RamDataType V_MEMROM2 SecM_MacPrimitivesContextBuffs[1] = {
   V_NULL
};

V_MEMROM0 V_MEMROM1 SecM_MacPrimitiveType V_MEMROM2 SecM_MacPrimitives[1] = {
   {
         SmhConf_SmhJob_SmhJob_Verify_ClassC
      ,  0u
      ,  V_NULL
      ,  FALSE
      ,  FALSE
   }
};

V_MEMROM0 V_MEMROM1 SecM_RamDataType V_MEMROM2 SecM_SignaturePrimitivesContextBuffs[1] = {
  V_NULL
};

V_MEMROM0 V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 SecM_SignaturePrimitives[1] = {
   {
         SmhConf_SmhJob_SmhJob_Verify_ClassCCC
      ,  SEC_INVALID_SMH_JOB_ID
      ,  NULL_PTR
      ,  0
      ,  0u
      ,  V_NULL
      ,  FALSE
   }
};

V_MEMROM0 V_MEMROM1 SecM_JobInfoType V_MEMROM2 SecM_JobInfo[4] = {
      {
            SECM_DECRYPTION
         ,  CsmConf_CsmJob_CsmJob_DecryptionAes128NoneCbc
         ,  CsmConf_CsmKey_CsmKey_Fbl_Decrypt_Aes128
         ,  SmhConf_SmhCryptographicKeys_AesKey
         ,  SEC_KEY_TYPE_AES
         ,  V_NULL
      }
   ,  {
            SECM_MACVERIFY
         ,  CsmConf_CsmJob_CsmJob_Signature_Class_C
         ,  CsmConf_CsmKey_CsmKey_Fbl_Signature_Class_C
         ,  SmhConf_SmhCryptographicKeys_ClassC_Key
         ,  SEC_KEY_TYPE_MAC
         ,  V_NULL
      }
   ,  {
            SECM_SIGNATUREVERIFY
         ,  CsmConf_CsmJob_CsmJob_SigAsymVer_RsaV15Sha1
         ,  CsmConf_CsmKey_CsmKey_Fbl_Signature_Rsa2048
         ,  SmhConf_SmhCryptographicKeys_ClassCCC_Rsa2048Key
         ,  SEC_KEY_TYPE_ASYMMETRIC
         ,  V_NULL
      }
   ,  {
            SECM_HASH
         ,  CsmConf_CsmJob_CsmJob_SigAsymVer_DummySha512
         ,  CsmConf_CsmKey_CsmKey_Fbl_HashDummy
         ,  SEC_INVALID_SMH_KEY_ID
         ,  SEC_KEY_TYPE_NONE
         ,  V_NULL
      }
};
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"
SecM_StatusType DecryptAes128(
      const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam
){
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pDecParam, SmhConf_SmhDecryption_SmhDecryptionConfig);
}

SecM_StatusType SecM_VerifyClass_DDD( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_StatusType result = SECM_NOT_OK;

   static SecM_CRC32ParamType  crc32Param;{
      if(pVerifyParam->sigState == SEC_HASH_INIT){
         pVerifyParam->currentHash.sigResultBuffer = (SecM_ResultBufferType)&crc32Param;
         pVerifyParam->currentHash.length = sizeof(crc32Param);
      }
      result = SecM_VerifyCrc(pVerifyParam, SmhConf_SmhStreamVerificationCrc_SmhSecurityClassDDDConfig);
   }
   return result;
}

SecM_StatusType SecM_Verify_ClassC( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   return SecM_VerifyMac(pVerifyParam, SmhConf_SmhStreamVerificationMac_SmhSecurityClassCConfig);
}

SecM_StatusType SecM_VerifyClass_CCC( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   return SecM_VerifySig(pVerifyParam, SmhConf_SmhStreamVerificationSignature_SmhSecurityClassCCCConfig);
}

SecM_StatusType SecM_VerificationClassDDD( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;
   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassDDDConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;
   return SecM_VerificationBase(pVerifyParam, &config);
}

SecM_StatusType SecM_Verification_ClassC( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;
   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassCConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;
   return SecM_VerificationBase(pVerifyParam, &config);
}

SecM_StatusType SecM_Verification_ClassCCC( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;
   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassCCCConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;
   return SecM_VerificationBase(pVerifyParam, &config);
}

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

