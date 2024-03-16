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
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[�˸�] ���� �ʱ�ȭ ����\n");

	// printf("wVersion: %d, wHighVersion: %d, szDescription: %d, szSystemStatus: %d\n", wsa.wVersion, wsa.wHighVersion, wsa.szDescription, wsa.szSystemStatus);

	// ���� ����
	SOCKET sock = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, NULL); // UDP
	if (sock == INVALID_SOCKET) err_quit("socket()");
	printf("[�˸�] ���� ���� ����\n");

	int retval = f(-100);
	if (retval == SOCKET_ERROR) err_quit("f()");

	// ���� �ݱ�
	closesocket(sock);

	// ���� ����
	WSACleanup();
	return 0;
}
