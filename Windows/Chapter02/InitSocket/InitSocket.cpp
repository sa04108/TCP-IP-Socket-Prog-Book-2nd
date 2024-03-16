#include "..\..\Common.h"

int f(int x) {
	if (x >= 0) {
		WSASetLastError(0);
		return 0;
	}
	else {
		WSASetLastError(WSAEINVAL);
		return SOCKET_ERROR;
	}
}

int main(int argc, char *argv[])
{
	// 윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[알림] 윈속 초기화 성공\n");

	// printf("wVersion: %d, wHighVersion: %d, szDescription: %d, szSystemStatus: %d\n", wsa.wVersion, wsa.wHighVersion, wsa.szDescription, wsa.szSystemStatus);

	// 소켓 생성
	SOCKET sock = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, NULL); // UDP
	if (sock == INVALID_SOCKET) err_quit("socket()");
	printf("[알림] 소켓 생성 성공\n");

	int retval = f(-100);
	if (retval == SOCKET_ERROR) err_quit("f()");

	// 소켓 닫기
	closesocket(sock);

	// 윈속 종료
	WSACleanup();
	return 0;
}
