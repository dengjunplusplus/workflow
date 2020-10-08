/*
  Copyright (c) 2019 Sogou, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

	  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Authors: Wu Jiaxu (wujiaxu@sogou-inc.com)
*/

#ifndef _PLATFORMSOCKET_H_
#define _PLATFORMSOCKET_H_

#include <sys/types.h>

#ifdef _WIN32

/*
	winsock.h and winsock2.h will conflict
	openssl 1.0 use winsock.h
	when we use openssl 1.0
	we should include winsock2.h before windows.h

	https://stackoverflow.com/questions/1372480/c-redefinition-header-files-winsock2-h
*/

#include <winsock2.h>
#include <windows.h>
#include <Ws2tcpip.h>
#include <Ws2def.h>

/*
typedef struct _WSABUF {
	ULONG len;
	CHAR  *buf;
} WSABUF, *LPWSABUF;
*/
struct iovec
{
	void *iov_base;
	size_t iov_len;
};

#else
# include <arpa/inet.h>
# include <sys/socket.h>
# include <sys/un.h>
# include <sys/uio.h>
# include <netdb.h>

#endif

#endif
