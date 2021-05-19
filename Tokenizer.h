//
// Created by pikachu on 5/19/2021.
//

#ifndef QTJIEBA_TOKENIZER_H
#define QTJIEBA_TOKENIZER_H
#include "QtJieba_global.h"
#include <QStringList>

namespace QtJieba {
    class TokenizerPrivate;
    class QTJIEBASHARED_EXPORT Tokenizer {
    public:
        Tokenizer();
        ~Tokenizer();
        QStringList cut(const QString& text);
    private:
        QtJieba::TokenizerPrivate *p;
    };

}

#endif //QTJIEBA_TOKENIZER_H
