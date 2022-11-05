/* 
MIT License 

Copyright (c) 2019 МГТУ им. Н.Э. Баумана, кафедра ИУ-6, Михаил Фетисов, 

Программа-заготовка для домашнего задания
*/

#ifndef LAB_L3_DOMAIN_LAYER_H
#define LAB_L3_DOMAIN_LAYER_H

#include "lab/l4_InfrastructureLayer.h"

//максимальгая длина названия и имени автора картины
const size_t MAX_NAME_LENGTH    = 100;
//год создания от 1 тысячилетия до нашего временни
const size_t MIN_draw_in  = 1000;
const size_t MAX_draw_in  = 2022;
//техника рисования 0 - масло; 1- графика; 2 - другое;
const size_t MIN_tech  = 0;
const size_t MAX_tech  = 2;

class Picture : public ICollectable
{
    std::string _picture_name;
    std::string _author_name;
    int _draw_in;
    int _technick; 


protected:
    bool invariant() const;

public:
    Picture() = delete;
    Picture(const Picture & p) = delete;

    Picture & operator = (const Picture & p) = delete;

    Picture(const std::string & picture_name, const std::string & author_name, int draw_in, int technick);

    const std::string & getPictureName() const;
    const std::string & getAuthorName() const;
    int getDrawIn() const;
    int Technick() const;


    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // LAB_L3_DOMAIN_LAYER_H
