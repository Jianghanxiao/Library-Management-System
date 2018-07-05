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
	cout << "��ӭ����ͼ�����ϵͳ�����Ѱָʾ�����Ĳ�����ÿ����ֻ��Ҫ����һ�����֣�������Enter��������ɲ���" << endl << endl;
	
	string pw_ad="jhx";
	string sqlstr = "";
	string a, cno, password, d, bno, b, c, e;
	MYSQL_RES *result = NULL;
	int rowcount;
	int tt=0;
	int ss = 0;

	while (1)
	{
		cout << "1������Ա��½		2:�û���½" << endl<<endl;
		cin >> a;
		cout << endl << endl;
		if (a[0] == '1')
		{
			while (1)
			{
				cout << "���������룺 ";
				cin >> password;
				cout << endl << endl;
				if (password == pw_ad)
				{
					while (1)
					{
						cout << "1:�鿴�����鼮		2.�޸��鼮��Ϣ		3.��������֤		4.��ѯ����֤"<<endl;
						cout << "5.ɾ������֤		6.����鼮		7.ɾ���鼮		8.�˳�" << endl << endl;
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
								cout << "��ܻ��ǿյ�" << endl << endl;
							}
						}
						else if (c[0] == '2')
						{
							while (1)
							{
								cout << "��������Ҫ�޸ĵ���Ϣ���" << endl;
								cout << "1:ͼ����		2:���		3:������		4:�۸�" << endl;
								cout << "5:�������		6:����		7:�˳�" << endl << endl;
								cin >> e;
								cout << endl << endl;
								if (e[0] != '7')
								{
									cout << "��������Ҫ�޸ĵ�ͼ����" << endl;
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
											cout << "������µ�ͼ����" << endl << endl;
											string title;
											cin >> title;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set title = '" + title + "' where bno ='" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else if (e[0] == '2')
										{
											cout << "������µ����" << endl << endl;
											string category;
											cin >> category;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set category = '" + category + "' where bno ='" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else if (e[0] == '3')
										{
											cout << "������µĳ�����" << endl << endl;
											string press;
											cin >> press;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set press = '" + press + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else if (e[0] == '4')
										{
											cout << "������µļ۸�" << endl << endl;
											string price;
											cin >> price;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set price = '" + price + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else if (e[0] == '5')
										{
											cout << "������µĳ������" << endl << endl;
											string year;
											cin >> year;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set year = '" + year + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else if (e[0] == '6')
										{
											cout << "������µ�����" << endl << endl;
											string author;
											cin >> author;
											cout << endl << endl;
											sqlstr = "";
											sqlstr += "update book set author = '" + author + "' where bno = '" + bno + "';";
											mysql_query(&mydata, sqlstr.c_str());
											cout << "�������" << endl << endl;
										}
										else break;
									}
									else
									{
										cout << "����δ��¼" << endl << endl;
									}
								}
								else break;
							}
						}
						else if (c[0] == '3')
						{
							cout << "�������봴���Ľ���֤id�� ";
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
								cout << "��Ϊ��ǰ�û��������룺 ";
								cin >> pw1;
								cout << endl << endl;
								cout << "�����뵱ǰ����֤���֣� ";
								cin >> name;
								cout << endl << endl;
								cout << "�����뵱ǰ����֤Ժϵ�� ";
								cin >> dep;
								cout << endl << endl;
								cout << "�����뵱ǰ����֤��� ";
								cin >> type;
								cout << endl << endl;
								sqlstr = "";
								sqlstr += "insert into card value('" + id + "','" + pw1 + "','" + name + "','" + dep + "','" + type + "');";
								if (mysql_query(&mydata, sqlstr.c_str()) == 0)
									cout << "�����ɹ�" << endl << endl;
								else
									cout << "����ʧ��" << endl << endl;
							}
							else
							{
								cout << "�û����Ѿ���ռ��" << endl << endl;
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
								cout << "��ǰû���κ��û�" << endl << endl;
							}
						}
						else if (c[0] == '5')
						{
							string id;
							cout << "����������ע���Ľ���֤�ţ� ";
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
										cout << "ע���ɹ�" << endl << endl;
									else
										cout << "ʧ��" << endl << endl;
								}
								else
								{
									cout << "��ǰ�û�����δ�黹���鼮��������ע��" << endl;
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
							else cout << "�޴��û�" << endl << endl;
						}
						else if (c[0] == '6')
						{
							string f;
							while (1)
							{
								cout << "1:��ӵ����鼮		2:��������鼮		3:�˳�" << endl;
								cin >> f;
								cout << endl << endl;
								if (f[0] == '1')
								{
									cout << "��������Ҫ��ӵ�ͼ���: ";
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
										cout << "������ͼ�����: ";
										cin >> cc;
										cout << endl << endl;
										cout << "������ͼ������: ";
										cin >> tt;
										cout << endl << endl;
										cout << "������ͼ�������: ";
										cin >> pp;
										cout << endl << endl;
										cout << "������ͼ��������: ";
										cin >> yy;
										cout << endl << endl;
										cout << "������ͼ������: ";
										cin >> aa;
										cout << endl << endl;
										cout << "������ͼ��۸�: ";
										cin >> pr;
										cout << endl << endl;
										sqlstr = "";
										sqlstr += "insert into book value('" + id + "','" + cc + "','" + tt + "','" + pp + "','" + yy + "','" + aa + "','" + pr + "',1,1);";
										if (mysql_query(&mydata, sqlstr.c_str()) == 0)
											cout << "���ͼ��ɹ�" << endl;
										else
											cout << "���ͼ��ʧ��" << endl;
									}
									else
									{
										sqlstr = "";
										sqlstr += "update book set total=total+1 where bno = '" + id + "';";
										mysql_query(&mydata, sqlstr.c_str());
										sqlstr = "";
										sqlstr += "update book set stock=stock+1 where bno = '" + id + "';";
										if (mysql_query(&mydata, sqlstr.c_str()) == 0)
											cout << "�����Ѿ����ڣ��Ѿ����������Ϳ��" << endl << endl;
										else
											cout << "�����Ѿ����ڣ����ʧ��" << endl << endl;
									}
								}
								else if (f[0] == '2')
								{
									int sss,kk=0;
									cout << "���������������ļ������� ";
									cin >> sss;
									cout << endl << endl;
									cout << "����������뵽in.txt�У�����ͼ��š�ͼ�����ͼ�����ơ�ͼ������硢ͼ�������ݡ�ͼ�����ߡ�ͼ��۸��˳��" << endl;
									cout << "��ɺ�������1" << endl;
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
													cout << "���ͼ��ɹ�" << endl << endl;
												else
													cout << "���ͼ��ʧ��" << endl << endl;
											}
											else
											{
												sqlstr = "";
												sqlstr += "update book set total=total+1 where bno = '" + id + "';";
												mysql_query(&mydata, sqlstr.c_str());
												sqlstr = "";
												sqlstr += "update book set stock=stock+1 where bno = '" + id + "';";
												if (mysql_query(&mydata, sqlstr.c_str()) == 0)
													cout << "�����Ѿ����ڣ��Ѿ����������Ϳ��" << endl << endl;
												else
													cout << "�����Ѿ����ڣ����ʧ��" << endl << endl;
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
							cout << "��������Ҫɾ��ͼ����: ";
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
									cout << "�Ѿ�ɾ���鼮" << endl << endl;
								}
								else
								{
									sqlstr = "";
									sqlstr += "update book set total=total-1 where bno = '" + id + "';";
									mysql_query(&mydata, sqlstr.c_str());
									cout << "�Ѿ����ٿ��" << endl << endl;
								}
							}
							else cout << "����δ��¼" << endl << endl;
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
					cout << "�㲻�ǹ���Ա" << endl << endl;
					break;
				}
			}
		}
		else if (a[0] == '2')
		{
			while (1)
			{
				cout << "�������û����� ";
				cin >> cno;
				cout << endl << endl;
				cout << "���������룺 ";
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
							cout << "1:����		2.����		3.��ѯ�����¼		4.ͼ���ѯ		5.����" << endl << endl;
							cin >> d;
							cout << endl << endl;
							if (d[0] == '1')
							{
								cout << "��������ţ� ";
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
												cout << "���ѳɹ��赽����" << endl << endl;
											}
											else
											{
												cout << "����δ�黹����" << endl << endl;
											}
										}
										else
										{
											cout << "�����Ѿ������" << endl << endl;
										}
									}
									else
									{
										cout << "����δ��¼" << endl << endl;
									}
								}
								else
								{
									cout << "��Ÿ�ʽ����ȷ" << endl << endl;
								}
							}
							else if (d[0] == '2')
							{
								cout << "��������ţ� ";
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
											cout << "���ѳɹ��黹����" << endl << endl;
										}
										else
										{
											cout << "��δ�������" << endl << endl;
										}
									}
									else
									{
										cout << "����δ��¼" << endl << endl;
									}
								}
								else
								{
									cout << "��Ÿ�ʽ����ȷ" << endl << endl;
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
									cout << "��û�н����κ�ͼ��" << endl<<endl;
								}
							}
							else if (d[0] == '4')
							{
								while (1)
								{
									cout << "��ѯ��ʽ��" << endl;
									cout << "1:ͼ����		2:ͼ����		3:���		4:������" << endl;
									cout << "5:�������		6:����		        7:�۸�		8:�˳�" << endl << endl;
									cin >> b;
									cout << endl << endl;
									if (b[0] == '1')
									{
										cout << "������ͼ����" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '2')
									{
										string title;
										cout << "������ͼ����" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '3')
									{
										string category;
										cout << "���������" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '4')
									{
										string press;
										cout << "�����������" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '5')
									{
										string year1,year2;
										cout << "�����뷢�����ڷ�Χ��ʼʱ��" << endl << endl;
										cin >> year1;
										cout << endl << endl;
										cout << "�����뷢�����ڷ�Χ����ʱ��" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '6')
									{
										string author;
										cout << "����������" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
										}
									}
									else if (b[0] == '7')
									{
										string price1, price2;
										cout << "������۸�Χ����" << endl << endl;
										cin >> price1;
										cout << endl << endl;
										cout << "������۸�Χ����" << endl << endl;
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
											cout << "����δ��¼" << endl << endl;
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
						cout << "�û������������" << endl<<endl;
						break;
					}
				}
				else
				{
					cout << "������Ч�û���" << endl<<endl;
					break;
				}
			}
		}
		else
		{
			cout << "������Ч�ַ�" << endl<<endl;
		}
	}

	mysql_close(&mydata);
	mysql_server_end();

	system("pause");
	return 0;
}