/*
 *  Author : WangBoJing , email : 1989wangbojing@gmail.com
 * 
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of Author. (C) 2017
 * 
 *

****       *****                                  ************
  ***        *                                    **   **    *
  ***        *         *                          *    **    **
  * **       *         *                         *     **     *
  * **       *         *                         *     **     *
  *  **      *        **                               **
  *  **      *       ***                               **
  *   **     *    ***********    *****    *****        **             *****         *  ****
  *   **     *        **           **      **          **           ***    *     **** *   **
  *    **    *        **           **      *           **           **     **      ***     **
  *    **    *        **            *      *           **          **      **      **       *
  *     **   *        **            **     *           **         **       **      **       **
  *     **   *        **             *    *            **         **               **       **
  *      **  *        **             **   *            **         **               **       **
  *      **  *        **             **   *            **         **               **       **
  *       ** *        **              *  *             **         **               **       **
  *       ** *        **              ** *             **         **               **       **
  *        ***        **               * *             **         **         *     **       **
  *        ***        **     *         **              **          **        *     **      **
  *         **        **     *         **              **          **       *      ***     **
  *         **         **   *          *               **           **     *       ****   **
*****        *          ****           *             ******           *****        **  ****
                                       *                                           **
                                      *                                            **
                                  *****                                            **
                                  ****                                           ******

 *
 */




#ifndef __NTY_EPOLL_H__
#define __NTY_EPOLL_H__

#include <stdint.h>
#include "nty_config.h"

typedef enum {

	NTY_EPOLLNONE 	= 0x0000,
	NTY_EPOLLIN 	= 0x0001,
	NTY_EPOLLPRI	= 0x0002,
	NTY_EPOLLOUT	= 0x0004,
	NTY_EPOLLRDNORM = 0x0040,
	NTY_EPOLLRDBAND = 0x0080,
	NTY_EPOLLWRNORM = 0x0100,
	NTY_EPOLLWRBAND = 0x0200,
	NTY_EPOLLMSG	= 0x0400,
	NTY_EPOLLERR	= 0x0008,
	NTY_EPOLLHUP 	= 0x0010,
	NTY_EPOLLRDHUP 	= 0x2000,
	NTY_EPOLLONESHOT = (1 << 30),
	NTY_EPOLLET 	= (1 << 31)

} nty_epoll_type;


typedef enum {
	NTY_EPOLL_CTL_ADD = 1,
	NTY_EPOLL_CTL_DEL = 2,
	NTY_EPOLL_CTL_MOD = 3,
} nty_epoll_op; 


typedef union _nty_epoll_data {
	void *ptr;
	int sockid;
	uint32_t u32;
	uint64_t u64;
} nty_epoll_data;

typedef struct {
	uint32_t events;
	uint64_t data;
} nty_epoll_event;


int nty_epoll_create(int size);
int nty_epoll_ctl(int epid, int op, int sockid, nty_epoll_event *event);
int nty_epoll_wait(int epid, nty_epoll_event *events, int maxevents, int timeout);


#if NTY_ENABLE_EPOLL_RB



enum EPOLL_EVENTS {
	EPOLLNONE 	= 0x0000,
	EPOLLIN 	= 0x0001,
	EPOLLPRI	= 0x0002,
	EPOLLOUT	= 0x0004,
	EPOLLRDNORM = 0x0040,
	EPOLLRDBAND = 0x0080,
	EPOLLWRNORM = 0x0100,
	EPOLLWRBAND = 0x0200,
	EPOLLMSG	= 0x0400,
	EPOLLERR	= 0x0008,
	EPOLLHUP 	= 0x0010,
	EPOLLRDHUP 	= 0x2000,
	EPOLLONESHOT = (1 << 30),
	EPOLLET 	= (1 << 31)

};

#define EPOLL_CTL_ADD	1
#define EPOLL_CTL_DEL	2
#define EPOLL_CTL_MOD	3

typedef union epoll_data {
	void *ptr;
	int fd;
	uint32_t u32;
	uint64_t u64;
} epoll_data_t;

struct epoll_event {
	uint32_t events;
	epoll_data_t data;
};

int epoll_create(int size);
int epoll_ctl(int epid, int op, int sockid, struct epoll_event *event);
int epoll_wait(int epid, struct epoll_event *events, int maxevents, int timeout);





#endif



#endif



