#ifndef _COMMONCRYPTO_COMMONDIGEST_H_
#define _COMMONCRYPTO_COMMONDIGEST_H_

#include <openssl/md5.h>

#define CC_MD5_DIGEST_LENGTH MD5_DIGEST_LENGTH
#define CC_MD5_CTX           MD5_CTX
#define CC_MD5_Init          MD5_Init
#define CC_MD5_Update        MD5_Update
#define CC_MD5_Final         MD5_Final
#define CC_MD5               MD5

#endif
