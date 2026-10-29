#include "01_reference(引用).h"

// 初始化指针域
Pointer *initPointer()
{
    Pointer *init = (Pointer *)calloc(1, sizeof(Pointer));
    if (init == NULL)
    {
        printf("指针域内存申请失败\n");
        exit(-1);
    }
    // calloc会自动置空
    return init;
}

// 航班—申请new—node
Flight *NewNode_f()
{
    Flight *ne = (Flight *)calloc(1, sizeof(Flight));
    if (ne == NULL)
    {
        printf("航班新节点内存申请失败\n");
        exit(-1);
    }
    return ne;
}

// 机票——申请new—nodet
Ticket *NewNode_t()
{
    Ticket *ne = (Ticket *)calloc(1, sizeof(Ticket));
    if (ne == NULL)
    {
        printf("机票新节点内存申请失败\n");
        exit(-1);
    }
    return ne;
}

// 航班—尾插
bool flight_tail_inset(Pointer *pt, char v1[50], char v2[50], char v3[50], int p, int s)
{
    Flight *ne = NewNode_f();
    strcpy(ne->flight_no, v1);
    strcpy(ne->from, v2);
    strcpy(ne->to, v3);
    ne->price = p;
    ne->seats = s;
    if (pt->Head_Flight == NULL) // 为真时就是空表
    {
        ne->prev = ne; // 指向自己
        ne->next = ne; // 指向自己
        pt->Head_Flight = ne;
    }
    else
    {
        ne->prev = pt->Head_Flight->prev;
        ne->next = pt->Head_Flight;
        ne->prev->next = ne;
        pt->Head_Flight->prev = ne;
    }

    return true;
}

// 机票—尾插
bool Ticket_tail_inset(Pointer *pt, int v1, char v2[50], char v3[50], char v4[50])
{
    Ticket *ne = NewNode_t();

    ne->order_no = v1;
    strcpy(ne->flight_no, v2);
    strcpy(ne->name, v3);
    strcpy(ne->phone, v4);

    if (pt->Head_Ticket == NULL) // 为真时就是空表
    {
        ne->prev = ne; // 指向自己
        ne->next = ne; // 指向自己
        pt->Head_Ticket = ne;
    }
    else
    {
        ne->prev = pt->Head_Ticket->prev;
        ne->next = pt->Head_Ticket;
        ne->prev->next = ne;
        pt->Head_Ticket->prev = ne;
    }

    return true;
}

// 航班—选择删除-用航班号
bool flight_Select_delete(Pointer *pt, char v1[50])
{
    if (pt->Head_Flight == NULL) // 为真时就是空表
    {
        printf("空表\n");
        return false;
    }

    Flight *topm = pt->Head_Flight;

    do
    {
        if (strcmp(topm->flight_no, v1) == 0)
        {
            if (pt->Head_Flight->next == pt->Head_Flight) // 为真时就是表里只有一个
            {
                topm = pt->Head_Flight;
                free(topm);
                pt->Head_Flight = NULL;
                return true;
            }
            // 判断当前位置
            if (topm->next == pt->Head_Flight) // 队尾
            {
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);
                return true;
            }
            if (topm == pt->Head_Flight) // 队头
            {
                pt->Head_Flight = topm->next;
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);

                return true;
            }
            else // 队身
            {
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);
                return true;
            }
        }
        topm = topm->next;

    } while (pt->Head_Flight != topm);

    printf("没找到对应航班，请检查后再删除\n");
    return false;
}

// 机票—选择删除-用订单号
bool Ticket_Select_delete(Pointer *pt, int v1)
{
    if (pt->Head_Ticket == NULL) // 为真时就是空表
    {
        printf("空表\n");
        return false;
    }
    //char v1[50];
    Ticket *topm = pt->Head_Ticket;

    do
    {
        if (topm->order_no == v1)
        {
            // Flight *topm1 = pt->Head_Flight;
            // strcpy(v1, topm1->flight_no);
            // int flog;
            // do
            // {
            //     if (strcmp(topm1->flight_no, v1) == 0)
            //     {
            //         flog=1;
            //         break;
            //     }
            //     topm1 = topm1->next;

            // } while (pt->Head_Flight != topm1);
            // if(flog)topm1->seats++;
            if (pt->Head_Ticket->next == pt->Head_Ticket) // 为真时就是表里只有一个
            {
                topm = pt->Head_Ticket;
                free(topm);
                pt->Head_Ticket = NULL;
                return true;
            }
            // 判断当前位置
            if (topm->next == pt->Head_Ticket) // 队尾
            {
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);
                return true;
            }
            if (topm == pt->Head_Ticket) // 队头
            {
                pt->Head_Ticket = topm->next;
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);

                return true;
            }
            else // 队身
            {
                topm->next->prev = topm->prev;
                topm->prev->next = topm->next;
                free(topm);
                return true;
            }
        }
        topm = topm->next;

    } while (pt->Head_Ticket != topm);

    printf("没找到对应机票，请检查后再删除\n");
    return false;
}

// 航班—遍历链表
void flight_print(Pointer *pt)
{
    if (pt->Head_Flight == NULL)
    {
        printf("暂无航班数据\n");
        return;
    }
    Flight *topm = pt->Head_Flight;
    do
    {
        // printf("\033[33m");
        printf("\033[33m航班号：\033[0m%s\t\033[33m出发地：\033[0m%s\t\033[33m目的地：\033[0m%s\t\033[33m票价：\033[0m%d \t\033[33m剩余座位：\033[0m%d\n",
               topm->flight_no, topm->from, topm->to, topm->price, topm->seats);
        // printf("\033[0m");
        topm = topm->next;

    } while (pt->Head_Flight != topm);
}
// 机票—遍历链表
void Ticket_print(Pointer *pt)
{
    if (pt->Head_Ticket == NULL)
    {
        printf("暂无机票数据\n");
        return;
    }
    Ticket *topm = pt->Head_Ticket;
    do
    {
        printf("\033[33m订单号：\033[0m%d \t\033[33m航班号：\033[0m%s\t\033[33m姓名：\033[0m%s \t\033[33m电话：\033[0m%s\n", topm->order_no, topm->flight_no, topm->name, topm->phone);
        topm = topm->next;

    } while (pt->Head_Ticket != topm);
}

// 打印主页选项
int home_option()
{

    system("clear");
    int option = 0;
    printf("\033[33m");
    printf("\n___________________________Air Ticket System___________________________\n");
    printf("\033[0m");
    printf("\n\t1.用户\n\t2.管理员\n\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    return option;
}

// 打印用户选项
int user_option()
{
    system("clear");
    int option = 0;
    printf("\033[33m");
    printf("\n_______________________________用户界面_________________________________\n");
    printf("\033[0m");
    printf("\n\t1.查询航班\n\t2.定购机票\n\t3.查询购票信息\n\t4.退订机票\n\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    return option;
}

// 查询航班
int search_option(Pointer *pt)
{
    system("clear");
    int option = 0;
    printf("\033[33m");
    printf("\n_______________________________查询航班_________________________________\n");
    printf("\033[0m");
    /*
    这个补充遍历航班列表

    */
    flight_print(pt);
    // printf("\n\t这个补充遍历航班列表\n");
    printf("\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ;
    return option;
}

// 订购机票
int add_Ticketing(Pointer *pt)
{
exit04:
    system("clear");

    flight_print(pt);
    int option = 0;

    printf("\033[33m");
    printf("\n_______________________________订购机票_________________________________\n");
    printf("\033[0m");

    static int v1 = 20261030;
    char v2[50];
    char v3[50];
    char v4[50];
    printf("\t航班号:");
    scanf("%s", v2);
    Flight *topm = pt->Head_Flight;
    int flog = 1;
    do
    {
        if (strcmp(topm->flight_no, v2) == 0)
        {
            flog = 0;
            break;
        }
        topm = topm->next;

    } while (pt->Head_Flight != topm);
    if (flog)
    {
        printf("\n\t\033[31m没有这个航班!!!\033[0m\n");
        // sleep(1);
        // return 1;
        goto exit12;
    }
    if (!topm->seats)
    {
        printf("\n\t\033[31m很抱歉 此次航班已无空位!!!\033[0m\n");
        goto exit13;
    }
    topm->seats--;
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t姓名:");
    scanf("%s", v3);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t联系方式:");
    scanf("%s", v4);
    while (getchar() != '\n')
        ; // 清空缓冲区

    Ticket_tail_inset(pt, v1, v2, v3, v4);
    printf("\n\t\033[33m订购成功!!!\033[0m\n");
exit12:
exit13:
    printf("\n\t1.继续订购\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    v1++;
    if (option == 1)
        goto exit04;
    return 0;
}

// 查询购票信息
int check_option(Pointer *pt)
{
    system("clear");
    int option = 0;
    printf("\033[33m");
    printf("\n_____________________________查询购票信息________________________________\n");
    printf("\033[0m");

    Ticket_print(pt);

    printf("\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ;
    return option;
}

// 退订机票
int refund_Ticketing(Pointer *pt)
{
exit06:
    system("clear");
    Ticket_print(pt);
    int option = 0;
    int xxx1;
    int xxx2;
    int xxx3;
    printf("\033[33m");
    printf("\n_______________________________退订机票_________________________________\n");
    printf("\033[0m");
    printf("\t机票号:");
    scanf("%d", &xxx1);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t确认退订(Y/N):");
    scanf("%d", &xxx2);
    while (getchar() != '\n')
        ; // 清空缓冲区

    if (Ticket_Select_delete(pt, xxx1))
    {
        printf("\n\t\033[33m退订成功!!!\033[0m\n");
        printf("\t很遗憾未能坐上我们飞机！！！\n");
    }
    else
    {
        printf("\n\t\033[31m退订失败!!!\033[0m\n");
    }

    printf("\n\n\t1.继续退订\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    if (option == 1)
        goto exit06;
    return 0;
}

// 非法输入
void illegal_output()
{
    printf("\033[31m");
    printf("\n============================ ⚠ 非法输入 ================================\n");
    printf("\033[0m");
    sleep(1);
}

// 打印管理员选项
int superuser_option()
{
    system("clear");
    int option = 0;
    printf("\033[33m");
    printf("\n______________________________管理员界面_________________________________\n");
    printf("\033[0m");
    printf("\n\t1.添加航班\n\t2.删除航班\n\t3.查询航班信息\n\t4.查询购票信息\n\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    return option;
}

// 添加航班
int add_flight(Pointer *pt)
{
exit08:
    system("clear");
    int option = 0;
    char xxx1[50];
    char xxx2[50];
    char xxx3[50];
    int xxx4;
    int xxx5;
    printf("\033[33m");
    printf("\n_______________________________添加航班_________________________________\n");
    printf("\033[0m");

    /*
    这里用尾插加入航班信息
    下面这些是案例（可以删）

    */
    printf("\t航班号:");
    scanf("%s", xxx1);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t出发地:");
    scanf("%s", xxx2);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t目的地:");
    scanf("%s", xxx3);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t票价:");
    scanf("%d", &xxx4);
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t剩余座位:");
    scanf("%d", &xxx5);
    while (getchar() != '\n')
        ; // 清空缓冲区

    flight_tail_inset(pt, xxx1, xxx2, xxx3, xxx4, xxx5);
    printf("\n\t\033[33m添加成功!!!\033[0m\n");

    printf("\n\n\t1.继续添加\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    if (option == 1)
        goto exit08;
    return 0;
}

// 删除航班
int delete_flight(Pointer *pt)
{
exit09:
    system("clear");
    flight_print(pt);
    int option = 0;
    char xxx1[50];
    int xxx2;

    printf("\033[33m");
    printf("\n_______________________________删除航班_________________________________\n");
    printf("\033[0m");
    printf("\t请输入航班号:");
    scanf("%s", xxx1);
    //== == = 1
    while (getchar() != '\n')
        ; // 清空缓冲区
    printf("\t确认删除航班(Y/N):");
    scanf("%d", &xxx2);
    while (getchar() != '\n')
        ; // 清空缓冲区
    // sleep(1);

    if (flight_Select_delete(pt, xxx1))
    {
        printf("\n\t\033[33m删除成功!!!\033[0m\n");
    }
    else
    {
        printf("\n\t\033[31m删除失败!!!\033[0m\n");
    }

    printf("\n\n\t1.继续删除\n\t-1.EXIT\n");
    scanf("%d", &option);
    while (getchar() != '\n')
        ; // 清空缓冲区
    if (option == 1)
        goto exit09;
    return 0;
}
