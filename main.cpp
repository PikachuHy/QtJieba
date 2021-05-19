//
// Created by pikachu on 5/19/2021.
//

#include "Tokenizer.h"
#include <QDebug>
int main() {
    QtJieba::Tokenizer tokenizer;
    qDebug() << tokenizer.cut("网易杭研大厦");
    qDebug() << tokenizer.cut("我来到北京清华大学");
    qDebug() << tokenizer.cut("小明硕士毕业于中国科学院计算所，后在日本京都大学深造");
    qDebug() << tokenizer.cut("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。");
    return 0;
}