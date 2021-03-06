#ifndef _COMMON_H_
#define _COMMON_H_

#include <cstdio>

#ifdef _WIN32
# ifdef DLLEXPORT
#  define DLLAPI __declspec(dllexport)
# else
#  define DLLAPI __declspec(dllimport)
# endif
#else
# define DLLAPI
#endif

#define IS_VALID_PCHAR(pchar)		(NULL != pchar && 0 != pchar[0])
#define IS_VALID_NUM_0EXCEPT(val)	(val > 0)
#define IS_VALID_NUM_0INCLUDE(val)	(val >= 0)
#define IS_VALID_ALPHABET(ch)		( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') )
#define IS_FORMAT_CH(ch)			(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')

#ifdef __cplusplus
# if defined(__FUNCTION__)
#  define POS_STRING_CPP				("FILE:" + __FILE__ + " FUNC:" + __FUNCTION__ + "LINE:" + __LINE__)
# elif defined(__func__)
#  define POS_STRING_CPP				("FILE:" + __FILE__ + " FUNC:" + __func__ + "LINE:" + __LINE__)
# else
#  define POS_STRING_CPP				("FILE:" + __FILE__ + "LINE:" + __LINE__)
# endif
#endif

#define		UNKNOW_ERROR					-1
#define		OK								0
#define		RBT_INIT_FAIL					-1001
#define		RBT_CONN_TIMEOUT				-1002
#define		RBT_LOGIN_FAIL					-1003
#define		RBT_CHANNEL_OPEN_FAIL			-1004
#define		RBT_DECLERE_EXCHANGE_FAIL		-1005
#define		RBT_BIND_FAIL					-1006
#define		RBT_PUBLISH_FAIL				-1007
#define		RBT_CONSUME_FAIL				-1008
#define		RBT_DECLERE_QUEUE_FAIL			-1009
#define		RBT_GET_FAIL					-1010
#define		RBT_GET_NOTHING					-1011
#define		RBT_GET_CONTENT_FAIL			-1012
#define		RBT_WRONG_FRAME					-1013

/** createNew = false : get last uniqueKey
 *  createNew = true : get a new uniqueKey
 */
inline std::string uniqueKey(bool createNew = true)
{
	static long long ikey = 0;
	char strkey[32] = {0};
	if (createNew) ikey++;
	sprintf(strkey, "%lld", ikey);
	return strkey;
}

#endif // _COMMON_H_
