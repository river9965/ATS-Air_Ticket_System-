#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#ifndef _REFERNCE_H_
#define _REFERNCE_H_

// 航班链表节点
typedef struct Flight
{
    char flight_no[50]; // 航班号
    char from[50];      // 出发地
    char to[50];        // 目的地
    int price;          // 票价
    int seats;          // 剩余座位
    struct Flight *prev;
    struct Flight *next;
} Flight;

// 购票（客户）链表节点
typedef struct Ticket
{
    int order_no;  // 订单号
    char flight_no[50]; // 坐哪个航班
    char name[50];      // 乘客姓名
    char phone[50];     // 电话号码
    struct Ticket *prev;
    struct Ticket *next;
} Ticket;

// 指针域
typedef struct Pointer_f
{
    Flight *Head_Flight; // 指向航班的首位
    Ticket *Head_Ticket; 
}Pointer;



/*==========================================
=============航班——链表功能区=================
===========================================*/
Pointer *initPointer();// 航班——初始化指针域
Flight *NewNode_f();// 航班——申请new—node
// 航班—尾插
bool flight_tail_inset(Pointer *pt, char v1[50], char v2[50], char v3[50], int p, int s);
bool flight_Select_delete(Pointer *pt, char v1[50]);// 航班—选择删除-用航班号
void flight_print(Pointer *pt);// 航班—遍历链表


/*==========================================
=============机票——链表功能区=================
===========================================*/

Ticket *NewNode_t();//机票——申请new—node
// 机票—尾插
bool Ticket_tail_inset(Pointer *pt, int v1, char v2[50], char v3[50],char v4[50]);
bool Ticket_Select_delete(Pointer *pt, int v1);// 机票—选择删除-用订单号
void Ticket_print(Pointer *pt);// 机票—遍历链表



int home_option();      // 打印主页选项
int user_option();      // 打印用户选项
int search_option(Pointer *pt);    // 查询航班
int add_Ticketing(Pointer *pt);    // 订购机票
int check_option(Pointer *pt);     // 查询购票信息
int refund_Ticketing(Pointer *pt); // 退订机票
int superuser_option(); // 打印管理员选项
int superuser_option(); // 打印管理员选项
int add_flight(Pointer *pt);       // 添加航班
int delete_flight(Pointer *pt);    // 删除航班
void illegal_output();  // 非法输入

#endif
