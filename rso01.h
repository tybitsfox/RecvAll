/*这是本人在windows下写过的一个数据包抓取、分析软件recvall的一个linux版本
  所有和界面相关的代码都放在链接库中完成。我爱死gtk的GUI编写方式了！
	Author:tybitsfox	2015-7-24
 */
#include"clsscr.h"
#include<gtk/gtk.h>
//{{{ all defines
#define		note_counts							4
#define		win_title							"RecvAll for Linux"
#define		win_width							640
#define		win_height							480
#define		offset								10
#define		bfix_w								win_width-offset
#define		bfix_h								win_height-offset
#define		nfix_w								win_width-35
#define		nfix_h								win_height-70
//定义第一页面的控件位置
#define		p1_lab1_x							8
#define		p1_lab1_y							12
#define		p1_lab1_w							50
#define		p1_lab1_h							16
#define		p1_lab1_t							"本机IP："

#define		p1_ed1_x							p1_lab1_x+p1_lab1_w+5
#define		p1_ed1_y							p1_lab1_y
#define		p1_ed1_w							120
#define		p1_ed1_h							20

#define		p1_ck_x								p1_ed1_x+p1_ed1_w+10
#define		p1_ck_y								p1_ed1_y+4
#define		p1_ck_w								88
#define		p1_ck_h								16
#define		p1_ck_t								"保存到文件"

#define		p1_bt1_x							p1_ck_x+p1_ck_w+15
#define		p1_bt1_y							p1_ed1_y
#define		p1_bt1_w							66
#define		p1_bt1_h							22
#define		p1_bt1_t							"开始监听"

#define		p1_bt2_x							p1_bt1_x+p1_bt1_w+10
#define		p1_bt2_y							p1_bt1_y
#define		p1_bt2_w							p1_bt1_w
#define		p1_bt2_h							p1_bt1_h
#define		p1_bt2_t							"停止监听"

#define		p1_bt3_x							p1_bt2_x+p1_bt2_w+70
#define		p1_bt3_y							p1_bt2_y
#define		p1_bt3_w							p1_bt2_w+14
#define		p1_bt3_h							p1_bt2_h
#define		p1_bt3_t							"装载包文件"

#define		p1_lab2_x							p1_lab1_x
#define		p1_lab2_y							p1_lab1_y+p1_lab1_h+12
#define		p1_lab2_w							p1_lab1_w
#define		p1_lab2_h							p1_lab1_h
#define		p1_lab2_t							"包过滤："

#define		p1_com1_x							p1_ed1_x
#define		p1_com1_y							p1_lab2_y-2
#define		p1_com1_w							90
#define		p1_com1_h							p1_ed1_h+4

#define		p1_lab3_x							p1_com1_x+p1_com1_w+5
#define		p1_lab3_y							p1_lab2_y
#define		p1_lab3_w							p1_lab2_w
#define		p1_lab3_h							p1_lab2_h
#define		p1_lab3_t							"指定IP："

#define		p1_ed2_x							p1_lab3_x+p1_lab3_w+5
#define		p1_ed2_y							p1_lab3_y
#define		p1_ed2_w							p1_ed1_w
#define		p1_ed2_h							p1_ed1_h

#define		p1_lab4_x							p1_ed2_x+p1_ed2_w+5
#define		p1_lab4_y							p1_lab3_y
#define		p1_lab4_w							p1_lab3_w+10
#define		p1_lab4_h							p1_lab3_h
#define		p1_lab4_t							"指定端口："

#define		p1_ed3_x							p1_lab4_x+p1_lab4_w+5
#define		p1_ed3_y							p1_ed2_y
#define		p1_ed3_w							50
#define		p1_ed3_h							p1_ed2_h

#define		p1_lab5_x							p1_ed3_x+p1_ed3_w+5
#define		p1_lab5_y							p1_lab4_y
#define		p1_lab5_w							130
#define		p1_lab5_h							20
#define		p1_lab5_t							"用于测试，测试～～～～～"

#define		p1_lab6_x							p1_lab2_x
#define		p1_lab6_y							p1_lab2_y+p1_lab2_h+8
#define		p1_lab6_w							p1_lab5_x-p1_lab2_x+130
#define		p1_lab6_h							p1_lab5_h
#define		p1_lab6_t							"测试lab6的字符串.............."

#define		p1_lst1_x							p1_lab6_x
#define		p1_lst1_y							p1_lab6_y+p1_lab6_h+8
#define		p1_lst1_w							p1_lab6_w-12
#define		p1_lst1_h							300

#define		p1_scro1_x							p1_lst1_x+p1_lst1_w
#define		p1_scro1_y							p1_lst1_y
#define		p1_scro1_w							18
#define		p1_scro1_h							300

//定义第二页面的空间位置
#define		p2_com1_x							8
#define		p2_com1_y							12
#define		p2_com1_w							p1_com1_w+16
#define		p2_com1_h							p1_com1_h

#define		p2_bnt1_x							p2_com1_x+p2_com1_w+10
#define		p2_bnt1_y							p2_com1_y+1
#define		p2_bnt1_w							p1_bt1_w
#define		p2_bnt1_h							p1_bt1_h
#define		p2_bnt1_t							"察    看"

#define		p2_lab1_x							p2_bnt1_x+p2_bnt1_w+10
#define		p2_lab1_y							p2_bnt1_y+3
#define		p2_lab1_w							385
#define		p2_lab1_h							p1_lab1_h
#define		p2_lab1_t							"测试，测试，测试，测试1，测试1，测试2，测试3，测试4，测试5测试5测试5测试5"

#define		p2_ed1_x							p2_com1_x
#define		p2_ed1_y							p2_com1_y+p2_com1_h+8
#define		p2_ed1_w							580
#define		p2_ed1_h							350

#define		p2_scro1_x							p2_ed1_x+p2_ed1_w
#define		p2_scro1_y							p2_ed1_y
#define		p2_scro1_w							18
#define		p2_scro1_h							p2_ed1_h




//定义第三页面的控件位置
#define		p3_lab1_x							p1_lab1_x
#define		p3_lab1_y							p1_lab1_y
#define		p3_lab1_w							100
#define		p3_lab1_h							16

//定义第四页面的控件位置
#define		p4_lab1_x							p1_lab1_x
#define		p4_lab1_y							p1_lab1_y
#define		p4_lab1_w							100
#define		p4_lab1_h							16



//}}}

//{{{ define all variables
GtkWidget	*window,*notebook,*bfix,*nfix[note_counts],*nlab[note_counts];
//定义第一页面的控件
enum{l_idx=0,l_type,l_spt,l_dpt,l_saddr,l_daddr,l_size,l_num};
GtkWidget	*lab1[6],*edit1[3],*bnt1[3],*chk1,*combo1,*list1,*scroll;
//定义第二页面的控件
GtkWidget	*lab2,*edit2,*bnt2,*combo2,*scrol2;

char	ntil[note_counts][100]={"监听界面","包分析","参数设置","说明"};
//}}}

//{{{ all functions
int crt_win(int argc,char** argv);
void crt_book1();
//页面一中列表框的初始化函数
void init_list(GtkWidget *widget);
void crt_book2();
void crt_book3();
void crt_book4();
void crt_nfix(int i);
int main(int argc,char** argv);

//}}}





















