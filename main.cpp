#include "all.h"

int main() {
    try {
        time_t now = time(nullptr);
        const tm *nowlt = localtime(&now);

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
        z << "日" << " : ";
        z << nowlt->tm_hour;
        z << "時";
        z << nowlt->tm_min;
        z << "分";
        z << nowlt->tm_sec;
        z << "秒";

        string result = z.str();

        // uru calc
        int redays = nowlt->tm_yday;
        int reyear = nowlt->tm_year;
        int oneday = 365 * (redays - 1);
        int uru = (reyear) / 100;
        int uru_keisan = (reyear >> 2) - uru + (uru >> 2);
        int keisan = (redays * 979 - 1033) >> 5;
        int nichisu = (oneday + uru_keisan + keisan) / 365;
        int redays_mini = 365 - nichisu + 27;

        // himekuri string
        string tim = "時刻を表示";
        string gantan = "来年の1月1日まであと";
        string aisatu = " 日です";
        string number = "日めくり数え番号";
        string week = "曜日";

        // week Sun ~ Sat
        time_t timer;
        struct tm *t_st;
        const char *wday[] = {"日", "月", "火", "水", "木", "金", "土"};

        time(&timer);
        t_st = localtime(&timer);

        stringstream ss;
        stringstream ssd;

        // version number
        ss << 1;
        ssd << 2;
        string str_num = ss.str();
        string str_dd = ssd.str();
        string comma = " : ";

        // version number comma
        string number_comma = ".0.";

        string himekuri = number + comma + str_num + number_comma + str_dd;

        cout << tim << comma << result << comma << wday[t_st->tm_wday] << week << endl;
        cout << gantan << comma << redays_mini << aisatu << endl;
        cout << result_reiwa << comma << result_r << endl;
        cout << himekuri << endl;

        // C++ version info.
        long cpp20 = 202002L;
        long cpp17 = 201703L;
        long cpp14 = 201402L;
        long cpp11 = 201103L;
        long cpp98 = 199711L;

        // long type → string type.
        string cpp_ver = to_string(__cplusplus);

        if (cpp_ver == to_string(cpp20))
            cout << "現在の C++ : C++20" << endl;
        else if (cpp_ver == to_string(cpp17))
            cout << "現在の C++ : C++17" << endl;
        else if (cpp_ver == to_string(cpp14))
            cout << "現在の C++ : C++14" << endl;
        else if (cpp_ver == to_string(cpp11))
            cout << "現在の C++ : C++11" << endl;
        else if (cpp_ver == to_string(cpp98))
            cout << "現在の C++ : C++98" << endl;
        else
            cout << "現在の C++ : pre-standard C++" << endl;

        return 0;
    }
    catch (const exception &e) {
        cerr << e.what();
    }
}