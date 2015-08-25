#include"rso01.h"

//{{{ int crt_win(int argc,char** argv)
int crt_win(int argc,char** argv)
{
	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window),win_width,win_height);
	gtk_window_set_title(GTK_WINDOW(window),win_title);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	notebook=gtk_notebook_new();
	crt_book1();
	crt_book2();
	bfix=gtk_fixed_new();
	gtk_widget_set_size_request(bfix,bfix_w,bfix_h);
	gtk_container_add(GTK_CONTAINER(window),bfix);
	gtk_fixed_put(GTK_FIXED(bfix),notebook,offset,offset);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}//}}}
//{{{ void	crt_book1()
void crt_book1()
{
	int i;
	nfix[0]=gtk_fixed_new();
	gtk_widget_set_size_request(nfix[0],nfix_w,nfix_h);
	lab1[0]=gtk_label_new(p1_lab1_t);
	gtk_widget_set_size_request(lab1[0],p1_lab1_w,p1_lab1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[0],p1_lab1_x,p1_lab1_y);
	edit1[0]=gtk_entry_new();
	gtk_widget_set_size_request(edit1[0],p1_ed1_w,p1_ed1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),edit1[0],p1_ed1_x,p1_ed1_y);
	chk1=gtk_check_button_new_with_label(p1_ck_t);
	gtk_widget_set_size_request(chk1,p1_ck_w,p1_ck_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),chk1,p1_ck_x,p1_ck_y);
	bnt1[0]=gtk_button_new_with_label(p1_bt1_t);
	gtk_widget_set_size_request(bnt1[0],p1_bt1_w,p1_bt1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),bnt1[0],p1_bt1_x,p1_bt1_y);
	bnt1[1]=gtk_button_new_with_label(p1_bt2_t);
	gtk_widget_set_size_request(bnt1[1],p1_bt2_w,p1_bt2_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),bnt1[1],p1_bt2_x,p1_bt2_y);
	bnt1[2]=gtk_button_new_with_label(p1_bt3_t);
	gtk_widget_set_size_request(bnt1[2],p1_bt3_w,p1_bt3_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),bnt1[2],p1_bt3_x,p1_bt3_y);
	lab1[1]=gtk_label_new(p1_lab2_t);
	gtk_widget_set_size_request(lab1[1],p1_lab2_w,p1_lab2_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[1],p1_lab2_x,p1_lab2_y);
	combo1=gtk_combo_box_new_text();
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"捕获全部");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"ICMP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"入TCP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"入UDP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"出TCP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"出UDP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"点对点TCP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"点对点UDP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"全部TCP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),"全部UDP");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo1),3);
	gtk_widget_set_size_request(combo1,p1_com1_w,p1_com1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),combo1,p1_com1_x,p1_com1_y);
	lab1[2]=gtk_label_new(p1_lab3_t);
	gtk_widget_set_size_request(lab1[2],p1_lab3_w,p1_lab3_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[2],p1_lab3_x,p1_lab3_y);
	edit1[1]=gtk_entry_new();
	gtk_widget_set_size_request(edit1[1],p1_ed2_w,p1_ed2_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),edit1[1],p1_ed2_x,p1_ed2_y);
	lab1[3]=gtk_label_new(p1_lab4_t);
	gtk_widget_set_size_request(lab1[3],p1_lab4_w,p1_lab4_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[3],p1_lab4_x,p1_lab4_y);
	edit1[2]=gtk_entry_new();
	gtk_widget_set_size_request(edit1[2],p1_ed3_w,p1_ed3_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),edit1[2],p1_ed3_x,p1_ed3_y);
	lab1[4]=gtk_label_new(p1_lab5_t);
	gtk_widget_set_size_request(lab1[4],p1_lab5_w,p1_lab5_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[4],p1_lab5_x,p1_lab5_y);
	lab1[5]=gtk_label_new(p1_lab6_t);
	gtk_widget_set_size_request(lab1[5],p1_lab6_w,p1_lab6_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),lab1[5],p1_lab6_x,p1_lab6_y);
	list1=gtk_tree_view_new();
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list1),TRUE);
	init_list(list1);
	gtk_widget_set_size_request(list1,p1_lst1_w,p1_lst1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),list1,p1_lst1_x,p1_lst1_y);
	scroll=gtk_vscrollbar_new(gtk_tree_view_get_vadjustment(GTK_TREE_VIEW(list1)));
	gtk_widget_set_size_request(scroll,p1_scro1_w,p1_scro1_h);
	gtk_fixed_put(GTK_FIXED(nfix[0]),scroll,p1_scro1_x,p1_scro1_y);

	nlab[0]=gtk_label_new(ntil[0]);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),nfix[0],nlab[0]);
}//}}}
//页面一中列表框的初始化函数
//{{{ void init_list(GtkWidget *widget)
//{{{
/*void init_list(GtkWidget *widget)
{
	GtkListStore	*store;
	GtkTreeModel	*model;
	GtkTreeViewColumn *column;
	GtkCellRenderer *render;
	store=gtk_list_store_new(l_num,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	model=GTK_TREE_MODEL(store);
	list1=gtk_tree_view_new_with_model(model);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("序    号",render,"text",l_idx,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("类    型",render,"text",l_type,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("源 端 口",render,"text",l_spt,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("目标端口",render,"text",l_dpt,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("源 地 址",render,"text",l_saddr,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("目标地址",render,"text",l_daddr,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
	render=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("包 长 度",render,"text",l_size,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list1),column);
//	g_object_unref(store);
}*/
//}}}
void init_list(GtkWidget *widget)
{
	GtkCellRenderer *render;
	GtkListStore *store;
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"序    号",render,"text",l_idx,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"类    型",render,"text",l_type,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"源 端 口",render,"text",l_spt,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"目标端口",render,"text",l_dpt,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"源 地 址",render,"text",l_saddr,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"目标地址",render,"text",l_daddr,NULL);
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(widget),-1,"包 长 度",render,"text",l_size,NULL);
	store=gtk_list_store_new(l_num,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(widget),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
//}}}
//{{{ void crt_book2()
void crt_book2()
{
	nfix[1]=gtk_fixed_new();
	gtk_widget_set_size_request(nfix[1],nfix_w,nfix_h);
	combo2=gtk_combo_box_new_text();
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo2),"查看包信息");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo2),"查看ip包头");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo2),"查看数据包头");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo2),"查看数据信息");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo2),0);
	gtk_widget_set_size_request(combo2,p2_com1_w,p2_com1_h);
	gtk_fixed_put(GTK_FIXED(nfix[1]),combo2,p2_com1_x,p2_com1_y);
	bnt2=gtk_button_new_with_label(p2_bnt1_t);
	gtk_widget_set_size_request(bnt2,p2_bnt1_w,p2_bnt1_h);
	gtk_fixed_put(GTK_FIXED(nfix[1]),bnt2,p2_bnt1_x,p2_bnt1_y);
	lab2=gtk_label_new(p2_lab1_t);
	gtk_widget_set_size_request(lab2,p2_lab1_w,p2_lab1_h);
	gtk_fixed_put(GTK_FIXED(nfix[1]),lab2,p2_lab1_x,p2_lab1_y);
	scrol2=gtk_scrolled_window_new(NULL,NULL);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrol2),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
	edit2=gtk_text_view_new();
	gtk_widget_set_size_request(edit2,p2_ed1_w,p2_ed1_h);
	gtk_container_add(GTK_CONTAINER(scrol2),edit2);
	gtk_fixed_put(GTK_FIXED(nfix[1]),scrol2,p2_ed1_x,p2_ed1_y);
//	scrol2=gtk_vscrollbar_new();
	

	nlab[1]=gtk_label_new(ntil[1]);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),nfix[1],nlab[1]);
}//}}}
//{{{ void crt_book3()
void crt_book3()
{
}//}}}
//{{{ void crt_book4()
void crt_book4()
{
}//}}}


//{{{ void crt_nfix(int i)
void crt_nfix(int i)
{

}//}}}

//{{{ int main(int argc,char** argv)
int main(int argc,char** argv)
{
	crt_win(argc,argv);
	return 0;
}//}}}















