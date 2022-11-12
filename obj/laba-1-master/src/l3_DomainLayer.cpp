/* Программа-заготовка для домашнего задания
*/

#include "lab/l3_DomainLayer.h"

using namespace std;


bool Picture::invariant() const
{
    return _technick >= MIN_tech && _technick <= MAX_tech
        && _draw_in >= MIN_draw_in && _draw_in <= MAX_draw_in
        && !_picture_name.empty() && _picture_name.size() <= MAX_NAME_LENGTH
        && !_author_name.empty() && _author_name.size() <= MAX_NAME_LENGTH;
}

Picture::Picture(const std::string & picture_name, const std::string & author_name, int draw_in, int technick)
    : _picture_name(picture_name), _author_name(author_name), _draw_in(draw_in), _technick(technick)
{
    
    assert(invariant());
}

const string & Picture::getPictureName() const
{
    return _picture_name;
}

const string & Picture::getAuthorName() const
{
    return _author_name;
}

int Picture::getDrawIn() const
{
    return _draw_in;
}

int Picture::Technick() const
{
 return _technick;
}

bool   Picture::write(ostream& os)
{
    writeString(os, _picture_name);
    writeString(os, _author_name);
    writeNumber(os, _draw_in);
    writeNumber(os, _technick);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   picture_name = readString(is, MAX_NAME_LENGTH);
    string   author_name = readString(is, MAX_NAME_LENGTH);
    int draw_in      = readNumber<int>(is);
    int technick      = readNumber<int>(is);

    return std::make_shared<Picture>(picture_name,author_name, draw_in, technick);
}
