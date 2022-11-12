#include <iostream>
#include <string>
#include "fstream"
#include "istream"

using namespace std;

int main()
{

    std::string str = "23EF5B9F1FFECF1F741ADBB05AFAA814AF2EE073A4F5D448670BDB343BC3FE0F7C5CC8253B479F362A471B57131100846139561BD37228569FB24B7E4D4CC06328D2FE8B1D659E3EE835B760B5F550295E5DC0E749EBA890CE17B6687787FC1EF8B9904A768F3E6C548E36AE26220108C272AC37A6E450AD3F6496FC9A9980C651A5FD163ACB3C7DD06B6EC16BEAA052BCBB81CE93D751219C2F6CD0EF0FF83DF1732094ED1E7CD8A91C6D5C4C44021184E5586F4DC8A15A7EC92DF93533018CA34BFA2C759678FBA0D6DD82D7D540A57977039D27AEA243385ED9A1DE1FF07BE2E64129DA3CF9B15238DAB89888042309CAB0DE9B9142B4FD925BF26A6603194697F458EB2CF1F741ADBB05AFAA814AF2EE073A4F5D448670BDB343BC3FE0F7C5CC8253B479F362A471B57131100846139561BD37228569FB24B7E4D4CC06328D2FE8B1D659E3EE835B760B5F550295E5DC0E749EBA890CE17B6687787FC1EF8B9904A768F3E6C548E36AE26220108C272AC37A6E450AD3F6496FC9A9980C651A5FD163ACB3C7DD06B6EC16BEAA052BCBB81CE93D751219C2F6CD0EF0FF83DF1732094ED1E7CD8A91C6D5C4C44021184E5586F4DC8A15A7EC92DF93533018CA34BFA2C759678FBA0D6DD82D7D540A57977039D27AEA243385ED9A1DE1FF07BE2E64129DA3CF9B15238DAB89888042309CAB0DE9B9142B4FD925BF26A6603194697F458EB2CF1F741ADBB05AFAA814AF2EE073A4F5D448670BDB343BC3FE0F7C5CC8253B479F362A471B57131100846139561BD37228569FB24B7E4D4CC06328D2FE8B1D659E3EE835B760B5F550295E5DC0E749EBA890CE17B6687787FC1EF8B9904A768F3E6C548E36AE26220108C272AC37A6E450AD3F6496FC9A9980C651A5FD163ACB3C7DD06B6EC16BEAA052BCBB81CE93D751219C2F6CD0EF0FF83DF1732094ED1E7CD8A91C6D5C4C44021184E5586F4DC8A15A7EC92DF93533018CA34BFA2C759678FBA0D6DD82D7D540A57977039D27AEA243385ED9A1DE1FF07BE2E64129DA3CF9B15238DAB89888042309CAB0DE9B9142B4FD925BF26A6603194697F458EB2CF1F741ADBB05AFAA814AF2EE073A4F5D448670BDB343BC3FE0F7C5CC8253B479F362A471B57131100846139561BD37228569FB24B7E4D4CC06328D2FE8B1D659E3EE835B760B5F550295E5DC0E749EBA890CE17B6687787FC1EF8B9904A768F3E6C548E36AE26220108C272AC37A6E450AD3F6496FC9A9980C651A5FD163ACB3C7DD06B6EC16BEAA052BCBB81CE93D751219C2F6CD0EF0FF83DF1732094ED1E7CD8A91C6D5C4C44021184E5586F4DC8A15A7EC92DF93533018CA34BFA2C759678FBA0D6DD82D7D540A57977039D27AEA243385ED9A1DE1FF07BE2E64129DA3CF9B15238DAB89888042309CAB0DE9B9142B4FD925BF26A6603194697F458EB2CF1F741ADBB05AFAA814AF2EE073A4F5D448670BDB343BC3FE0F7C5CC8253B479F362A471B57131100846139561BD37228569FB24B7E4D4CC06328D2FE8B1D659E3EE835B760B5F550295E5DC0E749EBA8010860004DA5";
    

    std::cout << str.length() << " " << str.length() / 2 << std::endl;

    string j = "stroka"; //строка, 6 элементов

    ofstream f("dta.bin", ios::binary | ios::trunc | ios::out); // тут нужно побитовое ИЛИ, а не логическое

    f.write(j.c_str(), j.length() + 1); // нельзя просто так взять адрес объекта, нужно сохранять содержимое строки
    f.flush();                          // не забудем сбросить данные на диск, а то рискуем получить пустую строку

    char cstrin[7]; // 7й - это ноль

    fstream f1("dta.bin", ios::binary | ios::in); // тут нужно побитовое ИЛИ, а не логическое

    f1.read(cstrin, 7); // читаем вместе с нулем

    cout << cstrin;

    system("pause");

    return 0;
}