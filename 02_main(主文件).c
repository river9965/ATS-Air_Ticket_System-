#include "01_reference(引用).h"

int main()
{
    //预存航班
    Pointer *pt=initPointer();
    char v1[50];
    char v2[50];
    char v3[50];
    strcpy(v1,"101");
    strcpy(v2,"广州");
    strcpy(v3,"上海");
    int v4=1971,v5=2;
    flight_tail_inset(pt,v1,v2,v3,v4,v5);
    strcpy(v1,"102");
    strcpy(v2,"深圳");
    strcpy(v3,"上海");
    v4=99,v5=2;
    flight_tail_inset(pt,v1,v2,v3,v4,v5);
    strcpy(v1,"103");
    strcpy(v2,"广州");
    strcpy(v3,"洛杉矶");
    v4=10000,v5=2;
    flight_tail_inset(pt,v1,v2,v3,v4,v5);


    while (1)
    {
        int home_opt = home_option(); // 主页选项
        switch (home_opt)
        {
        // 用户界面
        case 1:
            while (1)
            {
                int user_opt = user_option(); // 用户选项
                switch (user_opt)
                {
                // 查看航班
                case 1:
                    while (1)
                    {

                        int sea_opt = search_option(pt); // 查看航班选线，只有一个退出
                        switch (sea_opt)
                        {
                        case -1:
                            goto exit03; // 跳出本次循环
                        default:
                            illegal_output(); // 非法输入
                            break;
                        }
                    }
                    exit03: // 跳出本次循环
                    break;

                // 定购机票
                case 2:
                    add_Ticketing(pt);
                    break;
                    exit04: // 跳出本次循环
                    break;

                // 查询购票信息
                case 3:
                    while (1)
                    {

                        int che_opt = check_option(pt); // 查看客户的购票信息，只有一个退出
                        switch (che_opt)
                        {
                        case -1:
                            goto exit05; // 跳出本次循环
                        default:
                            illegal_output(); // 非法输入
                            break;
                        }
                    }
                    exit05: // 跳出本次循环
                    break;

                // 退订机票
                case 4:
                    refund_Ticketing(pt);
                    break;
                    exit06: // 跳出本次循环
                    break;

                // 退出
                case -1:
                    goto exit02; // 跳出本次循环

                default:
                    illegal_output(); // 非法输入
                    break;
                }
            }
        exit02:
            break;

            // 管理员界面
        case 2:
            while (1)
            {

                int super_opt = superuser_option(); // 管理员选项
                switch (super_opt)
                {

                // 添加航班
                case 1:
                    add_flight(pt);
                    break;

                // 删除航班
                case 2:
                    delete_flight(pt);
                    break;

                // 查询航班信息
                case 3:
                    while (1)
                    {

                        int sea_opt = search_option(pt); // 查看航班选线，只有一个退出
                        switch (sea_opt)
                        {
                        case -1:
                            goto exit10; // 跳出本次循环
                        default:
                            illegal_output(); // 非法输入
                            break;
                        }
                    }
                    exit10: // 跳出本次循环
                    break;

                // 查询机票信息
                case 4:
                    while (1)
                    {

                        int che_opt = check_option(pt); // 查看客户的购票信息，只有一个退出
                        switch (che_opt)
                        {
                        case -1:
                            goto exit11; // 跳出本次循环
                        default:
                            illegal_output(); // 非法输入
                            break;
                        }
                    }
                    exit11: // 跳出本次循环
                    break;

                // 退出
                case -1:
                    goto exit07; // 跳出本次循环
                default:
                    illegal_output(); // 非法输入
                    break;
                }
            }
        exit07: // 跳出本次循环
            break;
        case -1:
            printf("\033[33m");
            printf("\n_______________________成功退出 祝您旅途愉快❤____________________________\n\n");
            printf("\033[0m");
            goto exit01; // 跳转到return 0

        default:
            illegal_output(); // 非法输入
        }
    }
    exit01:
    return 0;
}
