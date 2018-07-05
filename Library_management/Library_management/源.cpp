#include<iostream>
#include<Windows.h>
#include <mysql.h>
#include<string>
#include<iomanip>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	MYSQL mydata;
	if (0 == mysql_library_init(0, NULL, NULL)) {
		;
	}
	else {
		cout << "mysql_library_init() failed" << endl;
		return -1;
	}
	if (NULL != mysql_init(&mydata)) {
		;
	}
	else {
		cout << "mysql_init() failed" << endl;
		return -1;
	}
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		;
	}
	else {
		cout << "mysql_options() failed" << endl;
		return -1;
	}
	if (NULL!= mysql_real_connect(&mydata, "localhost", "root", "Jhx980518", "lab5",3306, NULL, 0))
	{
		;
	}
	else {
		cout << "mysql_real_connect() failed" << endl;
		return -1;
	}
	cout << "欢迎来到图书管理系统，请跟寻指示完成你的操作，每次你只需要输入一个数字，并键入Enter建即可完成操作" << endl << endl;
	
	string pw_ad="jhx";
	string sqlstr = "";
	string a, cno, password, d, bno, b, c, e;
	MYSQL_RES *result = NULL;
	int rowcount;
	int tt=0;
	int ss = 0;

	while (1)
	{
		cout << "1：管理员登陆		2:用户登陆" << endl<<endl;
		cin >> a;
		cout << endl << endl;
		if (a[0] == '1')
		{
			while (1)
			{
				cout << "请输入密码： ";
				cin >> password;
				cout << endl << endl;
				if (password == pw_ad)
				{
					while (1)
					{
						cout << "1:查看所有书籍		2.修改书籍信息		3.创建借书证		4.查询借书证"<<endl;
						cout << "5.删除借书证		6.添加书籍		7.删除书籍		8.退出" << endl << endl;
						cin >> c;
						cout << endl << endl;
						if (c[0] == '1')
						{
							sqlstr = "";
							sqlstr += "select * from book;";
							mysql_query(&mydata, sqlstr.c_str());
							result = mysql_store_result(&mydata);
							rowcount = mysql_num_rows(result);
							if (rowcount != 0)
							{
								unsigned int fieldcount = mysql_num_fields(result);
								MYSQL_FIELD *field = NULL;
								for (unsigned int i = 0; i < fieldcount; i++) {
									field = mysql_fetch_field_direct(result, i);
									cout << left << setw(12) << field->name;
								}
								cout << endl;

								MYSQL_ROW row = NULL;
								row = mysql_fetch_row(result);
								while (NULL != row) {
									for (int i = 0; i < fieldcount; i++) {
										cout << left << setw(12) << row[i];
									}
									cout << endl;
									row = mysql_fetch_row(result);
								}
								cout << endl << endl;
							}
							else
							{
								cout << "书架还是空的" << endl << endl;
							}
						}
						else if (c[0] == '2')
						{
							while (1)
							{
								cout << "请输入想要修改的信息类别：" << endl;
								cout << "1:图书名		2:类别		3:出版社		4:价格" << endl;
								cout << "5:出版年份		6:作者		7:退出" << endl << endl;
								cin >> e;
								cout << endl << endl;
								if (e[0] != '7')
								{
									cout << "请输入想要修改的图书编号" << endl;
									cin >> bno;
									cout << endl << endl;
									sqlstr = "";
									sqlstr += "select * from book where bno = '" + bno + "';";
									mysql_query(&mydata, sqlstr.c_str());
									result = mysql_store_result(&mydata);
									rowcount = mysql_num_rows(result);
									if (rowcount != 0)
									{
										unsigned int fieldcount = mysql_num_fields(result);
										MYSQL_FIELD *field = NULL;
										for (unsigned int i = 0; i < fieldcount; i++) {
											field = mysql_fetch_field_direct(result, i);
											cout << left << setw(12) << field->name;
										}
										cout << endl;

										MYSQL_ROW row = NULL;
										row = mysql_fetch_row(result);
										while (NULL != row) {
											for (int i = 0; i < fieldcount; i++) {
												cout << left << setw(12) << row[i];
											}
											cout << endl;
											row = mysql_fetch_row(result);
										}
										cout << endl << endl;
										if (e[0] == '1')
										{
											cout << "请输出新的图书名" << endl << endl;
											string title;
											cin >> title;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set title = '" + title + "' where bno ='" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else if (e[0] == '2')
										{
											cout << "请输出新的类别" << endl << endl;
											string category;
											cin >> category;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set category = '" + category + "' where bno ='" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else if (e[0] == '3')
										{
											cout << "请输出新的出版社" << endl << endl;
											string press;
											cin >> press;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set press = '" + press + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else if (e[0] == '4')
										{
											cout << "请输出新的价格" << endl << endl;
											string price;
											cin >> price;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set price = '" + price + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else if (e[0] == '5')
										{
											cout << "请输出新的出版年份" << endl << endl;
											string year;
											cin >> year;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set year = '" + year + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else if (e[0] == '6')
										{
											cout << "请输出新的作者" << endl << endl;
											string author;
											cin >> author;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set author = '" + author + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "更新完成" << endl << endl;
										}
										else break;
									}
									else
									{
										cout << "该书未收录" << endl << endl;
									}
								}
								else break;
							}
						}
						else if (c[0] == '3')
						{
							cout << "请输入想创建的借书证id： ";
							string id, pw1, name, dep, type;
							cin >> id;
							cout << endl << endl;
							sqlstr = "";
							sqlstr += "select * from card where cno = '" + id + "';";
							mysql_query(&mydata, sqlstr.c_str());
							result = mysql_store_result(&mydata);
							rowcount = mysql_num_rows(result);
							if (rowcount == 0)
							{
								cout << "请为当前用户创建密码： ";
								cin >> pw1;
								cout << endl << endl;
								cout << "请输入当前借书证名字： ";
								cin >> name;
								cout << endl << endl;
								cout << "请输入当前借书证院系： ";
								cin >> dep;
								cout << endl << endl;
								cout << "请输入当前借书证类别： ";
								cin >> type;
								cout << endl << endl;
								sqlstr = "";
								sqlstr += "insert into card value('" + id + "','" + pw1 + "','" + name + "','" + dep + "','" + type + "');";
								if (mysql_query(&mydata, sqlstr.c_str()) == 0)
									cout << "创建成功" << endl << endl;
								else
									cout << "创建失败" << endl << endl;
							}
							else
							{
								cout << "用户名已经被占用" << endl << endl;
							}
						}
						else if (c[0] == '4')
						{
							sqlstr = "";
							sqlstr += "select * from card;";
							mysql_query(&mydata, sqlstr.c_str());
							result = mysql_store_result(&mydata);
							rowcount = mysql_num_rows(result);
							if (rowcount != 0)
							{
								unsigned int fieldcount = mysql_num_fields(result);
								MYSQL_FIELD *field = NULL;
								for (unsigned int i = 0; i < fieldcount; i++) {
									field = mysql_fetch_field_direct(result, i);
									cout << left << setw(20) << field->name;
								}
								cout << endl;

								MYSQL_ROW row = NULL;
								row = mysql_fetch_row(result);
								while (NULL != row) {
									for (int i = 0; i < fieldcount; i++) {
										cout << left << setw(20) << row[i];
									}
									cout << endl;
									row = mysql_fetch_row(result);
								}
								cout << endl << endl;
							}
							else
							{
								cout << "当前没有任何用户" << endl << endl;
							}
						}
						else if (c[0] == '5')
						{
							string id;
							cout << "请输入你想注销的借书证号： ";
							cin >> id;
							cout << endl << endl;
							sqlstr = "";
							sqlstr += "select * from card where cno = '" + id + "';";
							mysql_query(&mydata, sqlstr.c_str());
							result = mysql_store_result(&mydata);
							rowcount = mysql_num_rows(result);
							if (rowcount != 0)
							{
								sqlstr = "";
								sqlstr += "select * from borrow where cno = '" + id + "';";
								mysql_query(&mydata, sqlstr.c_str());
								result = mysql_store_result(&mydata);
								rowcount = mysql_num_rows(result);
								if (rowcount == 0)
								{
									sqlstr = "";
									sqlstr += "delete from card where cno = '" + id + "';";
									if (mysql_query(&mydata, sqlstr.c_str()) == 0)
										cout << "注销成功" << endl << endl;
									else
										cout << "失败" << endl << endl;
								}
								else
								{
									cout << "当前用户还有未归还的书籍，不可以注销" << endl;
									unsigned int fieldcount = mysql_num_fields(result);
									MYSQL_FIELD *field = NULL;
									for (unsigned int i = 0; i < fieldcount; i++) {
										field = mysql_fetch_field_direct(result, i);
										cout << left << setw(20) << field->name;
									}
									cout << endl;

									MYSQL_ROW row = NULL;
									row = mysql_fetch_row(result);
									while (NULL != row) {
										for (int i = 0; i < fieldcount; i++) {
											cout << left << setw(20) << row[i];
										}
										cout << endl;
										row = mysql_fetch_row(result);
									}
									cout << endl << endl;
								}
							}
							else cout << "无此用户" << endl << endl;
						}
						else if (c[0] == '6')
						{
							string f;
							while (1)
							{
								cout << "1:添加单本书籍		2:批量添加书籍		3:退出" << endl;
								cin >> f;
								cout << endl << endl;
								if (f[0] == '1')
								{
									cout << "请输入想要添加的图书号: ";
									string id;
									cin >> id;
									cout << endl << endl;
									sqlstr = "";
									sqlstr += "select * from book where bno = '" + id + "';";
									mysql_query(&mydata, sqlstr.c_str());
									result = mysql_store_result(&mydata);
									rowcount = mysql_num_rows(result);
									if (rowcount == 0)
									{
										string cc, tt, pp, yy, aa, pr;
										cout << "请输入图书类别: ";
										cin >> cc;
										cout << endl << endl;
										cout << "请输入图书名称: ";
										cin >> tt;
										cout << endl << endl;
										cout << "请输入图书出版社: ";
										cin >> pp;
										cout << endl << endl;
										cout << "请输入图书出版年份: ";
										cin >> yy;
										cout << endl << endl;
										cout << "请输入图书作者: ";
										cin >> aa;
										cout << endl << endl;
										cout << "请输入图书价格: ";
										cin >> pr;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "insert into book value('" + id + "','" + cc + "','" + tt + "','" + pp + "','" + yy + "','" + aa + "','" + pr + "',1,1);";
										if (mysql_query(&mydata, sqlstr.c_str()) == 0)
											cout << "添加图书成功" << endl;
										else
											cout << "添加图书失败" << endl;
									}
									else
									{
										sqlstr = "";
										sqlstr += "update book set total=total+1 where bno = '" + id + "';";
										mysql_query(&mydata, sqlstr.c_str());
										sqlstr = "";
										sqlstr += "update book set stock=stock+1 where bno = '" + id + "';";
										if (mysql_query(&mydata, sqlstr.c_str()) == 0)
											cout << "该书已经存在，已经增加总量和库存" << endl << endl;
										else
											cout << "该书已经存在，添加失败" << endl << endl;
									}
								}
								else if (f[0] == '2')
								{
									int sss,kk=0;
									cout << "请输入批量输入文件总数： ";
									cin >> sss;
									cout << endl << endl;
									cout << "请把数据输入到in.txt中，按照图书号、图书类别、图书名称、图书出版社、图书出版年份、图书作者、图书价格的顺序" << endl;
									cout << "完成后请输入1" << endl;
									cin >> kk;
									if (kk == 1)
									{
										ifstream file1("in.txt");
										for (int i = 1; i <= sss; ++i)
										{
											string id,cc, tt, pp, yy, aa, pr;
											file1 >> id;
											file1 >> cc;
											file1 >> tt;
											file1 >> pp;
											file1 >> yy;
											file1 >> aa;
											file1 >> pr;
											sqlstr = "";
											sqlstr += "select * from book where bno = '" + id + "';";
											mysql_query(&mydata, sqlstr.c_str());
											result = mysql_store_result(&mydata);
											rowcount = mysql_num_rows(result);
											if (rowcount == 0)
											{
												sqlstr = "";
												sqlstr += "insert into book value('" + id + "','" + cc + "','" + tt + "','" + pp + "','" + yy + "','" + aa + "','" + pr + "',1,1);";
												if (mysql_query(&mydata, sqlstr.c_str()) == 0)
													cout << "添加图书成功" << endl << endl;
												else
													cout << "添加图书失败" << endl << endl;
											}
											else
											{
												sqlstr = "";
												sqlstr += "update book set total=total+1 where bno = '" + id + "';";
												mysql_query(&mydata, sqlstr.c_str());
												sqlstr = "";
												sqlstr += "update book set stock=stock+1 where bno = '" + id + "';";
												if (mysql_query(&mydata, sqlstr.c_str()) == 0)
													cout << "该书已经存在，已经增加总量和库存" << endl << endl;
												else
													cout << "该书已经存在，添加失败" << endl << endl;
											}
										}
										file1.close();
									}
								}
								else break;
							}
						}
						else if (c[0] == '7')
						{
							cout << "请输入想要删除图书编号: ";
							string id;
							cin >> id;
							cout << endl << endl;
							sqlstr = "";
							sqlstr += "select * from book where bno = '" + id + "';";
							mysql_query(&mydata, sqlstr.c_str());
							result = mysql_store_result(&mydata);
							rowcount = mysql_num_rows(result);
							if (rowcount != 0)
							{
								sqlstr = "";
								sqlstr += "select * from book where bno = '" + id + "' and total = 1;";
								mysql_query(&mydata, sqlstr.c_str());
								result = mysql_store_result(&mydata);
								rowcount = mysql_num_rows(result);
								if (rowcount != 0)
								{
									sqlstr = "";
									sqlstr += "delete from book where bno = '" + id + "';";
									mysql_query(&mydata, sqlstr.c_str());
									cout << "已经删除书籍" << endl << endl;
								}
								else
								{
									sqlstr = "";
									sqlstr += "update book set total=total-1 where bno = '" + id + "';";
									mysql_query(&mydata, sqlstr.c_str());
									cout << "已经减少库存" << endl << endl;
								}
							}
							else cout << "该书未收录" << endl << endl;
						}
						else
						{
							ss = 1;
							break;
						}
					}
					if (ss == 1)
					{
						ss = 0;
						break;
					}
				}
				else
				{
					cout << "你不是管理员" << endl << endl;
					break;
				}
			}
		}
		else if (a[0] == '2')
		{
			while (1)
			{
				cout << "请输入用户名： ";
				cin >> cno;
				cout << endl << endl;
				cout << "请输入密码： ";
				cin >> password;
				cout << endl << endl;
				sqlstr = "";
				sqlstr += "select * from card where cno = '" + cno + "' and password = '" + password + "';";
				if (mysql_query(&mydata, sqlstr.c_str()) == 0)
				{
					result = mysql_store_result(&mydata);
					rowcount = mysql_num_rows(result);
					if (rowcount != 0)
					{
						while (1)
						{
							cout << "1:借书		2.还书		3.查询借书记录		4.图书查询		5.返回" << endl << endl;
							cin >> d;
							cout << endl << endl;
							if (d[0] == '1')
							{
								cout << "请输入书号： ";
								cin >> bno;
								cout << endl << endl;
								sqlstr = "";
								sqlstr += "select * from book where bno = '" + bno + "';";
								if (mysql_query(&mydata, sqlstr.c_str()) == 0)
								{
									result = mysql_store_result(&mydata);
									rowcount = mysql_num_rows(result);
									if (rowcount != 0)
									{
										sqlstr = "";
										sqlstr += "select * from book where bno = '" + bno + "' and stock > 0;";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											sqlstr = "";
											sqlstr += "insert into borrow values ('" + cno + "','" + bno + "',2018,4);";
											if (mysql_query(&mydata, sqlstr.c_str()) == 0)
											{
												sqlstr = "";
												sqlstr += "update book set stock=stock-1 where bno = '" + bno + "';";
												mysql_query(&mydata, sqlstr.c_str());
												cout << "您已成功借到该书" << endl << endl;
											}
											else
											{
												cout << "您还未归还该书" << endl << endl;
											}
										}
										else
										{
											cout << "该书已经被借光" << endl << endl;
										}
									}
									else
									{
										cout << "该书未收录" << endl << endl;
									}
								}
								else
								{
									cout << "书号格式不正确" << endl << endl;
								}
							}
							else if (d[0] == '2')
							{
								cout << "请输入书号： ";
								cin >> bno;
								cout << endl << endl;
								sqlstr = "";
								sqlstr += "select * from book where bno = '" + bno + "';";
								if (mysql_query(&mydata, sqlstr.c_str()) == 0)
								{
									result = mysql_store_result(&mydata);
									rowcount = mysql_num_rows(result);
									if (rowcount != 0)
									{
										sqlstr = "";
										sqlstr += "select * from borrow where bno = '" + bno + "' and cno ='"+cno+"';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											sqlstr = "";
											sqlstr += "delete from borrow where bno = '"+bno + "' and cno ='" + cno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											sqlstr = "";
											sqlstr += "update book set stock=stock+1 where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "您已成功归还该书" << endl << endl;
										}
										else
										{
											cout << "您未借过该书" << endl << endl;
										}
									}
									else
									{
										cout << "该书未收录" << endl << endl;
									}
								}
								else
								{
									cout << "书号格式不正确" << endl << endl;
								}
							}
							else if (d[0] == '3')
							{
								sqlstr = "";
								sqlstr += "select * from borrow where cno ='" + cno + "';";
								mysql_query(&mydata, sqlstr.c_str());
								result = mysql_store_result(&mydata);
								rowcount = mysql_num_rows(result);
								if (rowcount != 0)
								{
									unsigned int fieldcount = mysql_num_fields(result);
									MYSQL_FIELD *field = NULL;
									for (unsigned int i = 0; i < fieldcount; i++) {
										field = mysql_fetch_field_direct(result, i);
										cout <<left<<setw(20)<< field->name ;
									}
									cout << endl;

									MYSQL_ROW row = NULL;
									row = mysql_fetch_row(result);
									while (NULL != row) {
										for (int i = 0; i < fieldcount; i++) {
											cout<<left<<setw(20) << row[i] ;
										}
										cout << endl;
										row = mysql_fetch_row(result);
									}
									cout << endl << endl;
								}
								else
								{
									cout << "您没有借阅任何图书" << endl<<endl;
								}
							}
							else if (d[0] == '4')
							{
								while (1)
								{
									cout << "查询方式：" << endl;
									cout << "1:图书编号		2:图书名		3:类别		4:出版社" << endl;
									cout << "5:出版年份		6:作者		        7:价格		8:退出" << endl << endl;
									cin >> b;
									cout << endl << endl;
									if (b[0] == '1')
									{
										cout << "请输入图书编号" << endl << endl;
										cin >> bno;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where bno = '" + bno + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '2')
									{
										string title;
										cout << "请输入图书名" << endl << endl;
										cin >> title;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where title = '" + title + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '3')
									{
										string category;
										cout << "请输入类别" << endl << endl;
										cin >> category;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where category = '" + category + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '4')
									{
										string press;
										cout << "请输入出版社" << endl << endl;
										cin >> press;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where press = '" + press + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '5')
									{
										string year1,year2;
										cout << "请输入发行日期范围开始时间" << endl << endl;
										cin >> year1;
										cout << endl << endl;
										cout << "请输入发行日期范围结束时间" << endl << endl;
										cin >> year2;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where year >= '" + year1 + "' and year <= '" + year2 + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '6')
									{
										string author;
										cout << "请输入作者" << endl << endl;
										cin >> author;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where author = '" + author + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else if (b[0] == '7')
									{
										string price1, price2;
										cout << "请输入价格范围下限" << endl << endl;
										cin >> price1;
										cout << endl << endl;
										cout << "请输入价格范围上限" << endl << endl;
										cin >> price2;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "select * from book where price >= '" + price1 + "' and price <= '" + price2 + "';";
										mysql_query(&mydata, sqlstr.c_str());
										result = mysql_store_result(&mydata);
										rowcount = mysql_num_rows(result);
										if (rowcount != 0)
										{
											unsigned int fieldcount = mysql_num_fields(result);
											MYSQL_FIELD *field = NULL;
											for (unsigned int i = 0; i < fieldcount; i++) {
												field = mysql_fetch_field_direct(result, i);
												cout << left << setw(12) << field->name;
											}
											cout << endl;

											MYSQL_ROW row = NULL;
											row = mysql_fetch_row(result);
											while (NULL != row) {
												for (int i = 0; i < fieldcount; i++) {
													cout << left << setw(12) << row[i];
												}
												cout << endl;
												row = mysql_fetch_row(result);
											}
											cout << endl << endl;
										}
										else
										{
											cout << "该书未收录" << endl << endl;
										}
									}
									else break;
								}
							}
							else
							{
								tt = 1;
								break;
							}
						}
						if (tt == 1)
						{
							tt = 0;
							break;
						}
					}
					else
					{
						cout << "用户名或密码错误" << endl<<endl;
						break;
					}
				}
				else
				{
					cout << "输入无效用户名" << endl<<endl;
					break;
				}
			}
		}
		else
		{
			cout << "输入无效字符" << endl<<endl;
		}
	}

	mysql_close(&mydata);
	mysql_server_end();

	system("pause");
	return 0;
}