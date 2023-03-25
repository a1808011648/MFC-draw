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

	MYSQL h_mysql;//mysql句柄
	MYSQL_RES* res;//数据集
	MYSQL_ROW row;//一行数据
	std::string name;
	std::string password;
	//初始化数据库
	mysql_init(&h_mysql);

	//设置字符编码
	mysql_options(&h_mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//连接数据库
	if (mysql_real_connect(&h_mysql, DB_HOST, DB_USER, DB_PASSWORD, DB_NAME, DB_PORT, NULL, 0) == NULL) {
		std::cout << "数据库连接失败,错误为：" << mysql_error(&h_mysql) << std::endl;
		::system("pause");
		return -1;
	}

	//验证用户
	std::cout << "请输入用户名：";
	std::cin >> name;
	std::cout << "请输入密码：";
	std::cin >> password;
	
	//查询是否存在
	std::stringstream sstr;
	std::string str;
	sstr << "select id,level_id from user where username='" << name << "' and password=md5('" << password << "');";
	str = sstr.str();

	//查询语句执行成功 会返回0
	int ret = mysql_query(&h_mysql, str.c_str());
	if (ret != 0) {
		std::cout << "查询出错，错误为：" << mysql_error(&h_mysql) << std::endl;
		//关闭连接 释放资源
		mysql_close(&h_mysql);
		::system("pause");
		return -1;
	}
	
	//获取查询到的数据集
	res = mysql_store_result(&h_mysql);

	//读取数据集，一行一行读取,如果读到为空跳出循环
	while (row = mysql_fetch_row(res)) {

		int id = atoi(row[0]);
		int level_id = atoi(row[1]);

		std::cout << "从数据集读取到的一行数据：" << id << "   " << level_id << std::endl;
	}

	//释放资源
	mysql_free_result(res);

	//关闭连接
	mysql_close(&h_mysql);

	::system("pause");
	return 0;
}