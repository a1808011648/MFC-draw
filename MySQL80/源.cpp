#include <iostream>
#include <mysql.h>
#include <string>
#include <sstream>
#define DB_HOST "127.0.0.1"
#define DB_USER "TanRongGui"
#define DB_PASSWORD "A1808011648trg!"
#define DB_NAME "game"
#define DB_PORT 3306
int main() {

	MYSQL h_mysql;//mysql���
	MYSQL_RES* res;//���ݼ�
	MYSQL_ROW row;//һ������
	std::string name;
	std::string password;
	//��ʼ�����ݿ�
	mysql_init(&h_mysql);

	//�����ַ�����
	mysql_options(&h_mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�
	if (mysql_real_connect(&h_mysql, DB_HOST, DB_USER, DB_PASSWORD, DB_NAME, DB_PORT, NULL, 0) == NULL) {
		std::cout << "���ݿ�����ʧ��,����Ϊ��" << mysql_error(&h_mysql) << std::endl;
		::system("pause");
		return -1;
	}

	//��֤�û�
	std::cout << "�������û�����";
	std::cin >> name;
	std::cout << "���������룺";
	std::cin >> password;
	
	//��ѯ�Ƿ����
	std::stringstream sstr;
	std::string str;
	sstr << "select id,level_id from user where username='" << name << "' and password=md5('" << password << "');";
	str = sstr.str();

	//��ѯ���ִ�гɹ� �᷵��0
	int ret = mysql_query(&h_mysql, str.c_str());
	if (ret != 0) {
		std::cout << "��ѯ��������Ϊ��" << mysql_error(&h_mysql) << std::endl;
		//�ر����� �ͷ���Դ
		mysql_close(&h_mysql);
		::system("pause");
		return -1;
	}
	
	//��ȡ��ѯ�������ݼ�
	res = mysql_store_result(&h_mysql);

	//��ȡ���ݼ���һ��һ�ж�ȡ,�������Ϊ������ѭ��
	while (row = mysql_fetch_row(res)) {

		int id = atoi(row[0]);
		int level_id = atoi(row[1]);

		std::cout << "�����ݼ���ȡ����һ�����ݣ�" << id << "   " << level_id << std::endl;
	}

	//�ͷ���Դ
	mysql_free_result(res);

	//�ر�����
	mysql_close(&h_mysql);

	::system("pause");
	return 0;
}