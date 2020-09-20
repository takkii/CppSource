#include "all.h"

auto main(void) -> int  // NOLINT(bugprone-exception-escape)
{
	try
	{
		time_t now = time(nullptr);
		// ReSharper disable once CppDeprecatedEntity
		const tm* nowlt = localtime(&now);

		stringstream x;
		x << "R0";
		x << nowlt->tm_year - 118;
		x << ".";
		x << nowlt->tm_mon + 1;
		x << ".";
		x << nowlt->tm_mday;

		string result_r = x.str();

		stringstream y;
		y << "令和";
		y << nowlt->tm_year - 118;
		y << "年";
		y << nowlt->tm_mon + 1;
		y << "月";
		y << nowlt->tm_mday;
		y << "日";

		string result_reiwa = y.str();


		stringstream z;
		z << "20";
		z << nowlt->tm_year - 100;
		z << "年";
		z << nowlt->tm_mon + 1;
		z << "月";
		z << nowlt->tm_mday;
		z << "日：";
		z << nowlt->tm_hour;
		z << "時";
		z << nowlt->tm_min;
		z << "分";
		z << nowlt->tm_sec;
		z << "秒";

		string result = z.str();

		int redays = nowlt->tm_yday;
		int reyear = nowlt->tm_year;
		int oneday = 365 * (redays - 1);
		int uru = (reyear) / 100;
		int uru_keisan = (reyear >> 2) - uru + (uru >> 2);
		int keisan = (redays * 979 - 1033) >> 5;
		int nichisu = (oneday + uru_keisan + keisan) / 365;
		int redays_mini = 365 - nichisu + 21;

		string tim = "時刻を表示";
		string gantan = "来年の1月1日まであと";
		string aisatu = " 日です";
		string number = "日めくり数え番号";
		string version = "1.0.1";
		string comma = " : ";

		string himekuri = number + comma + version;

		cout << tim << comma << result << endl;
		cout << gantan << comma << redays_mini << aisatu << endl;
		cout << result_reiwa << comma << result_r << endl;
		cout << himekuri << endl;

		return 0;
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
}
