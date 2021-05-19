//
// Created by pikachu on 5/19/2021.
//

#include "Tokenizer.h"
#include "cppjieba/Jieba.hpp"
#include <QDebug>
#include <QFile>
using namespace std;

const char* const DICT_PATH = "dict/jieba.dict.utf8";
const char* const HMM_PATH = "dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "dict/user.dict.utf8";
const char* const IDF_PATH = "dict/idf.utf8";
const char* const STOP_WORD_PATH = "dict/stop_words.utf8";

using namespace QtJieba;
namespace QtJieba {
    class TokenizerPrivate {
    public:
        TokenizerPrivate() {
            qDebug() << "tokenizer loading!";
            QStringList dataPathList;
            dataPathList << DICT_PATH;
            dataPathList << HMM_PATH;
            dataPathList << USER_DICT_PATH;
            dataPathList << IDF_PATH;
            dataPathList << STOP_WORD_PATH;
            for (const QString& path: dataPathList) {
                if (!QFile(path).exists()) {
                    qCritical() << "data file not exist." << path;
                    exit(0);
                }
            }
            m_jieba = new cppjieba::Jieba(DICT_PATH,
                                          HMM_PATH,
                                          USER_DICT_PATH,
                                          IDF_PATH,
                                          STOP_WORD_PATH);
            qDebug() << "tokenizer load done!";
        }
        ~TokenizerPrivate() {
            delete m_jieba;
        }
        QStringList cut(const QString& text) {
            QStringList ret;
            vector<string> words;
            m_jieba->Cut(text.toStdString(), words, true);
            for(const auto& word: words) {
                ret.push_back(QString::fromStdString(word));
            }
            return ret;
        }
    private:
        cppjieba::Jieba* m_jieba;
    };
}

Tokenizer::Tokenizer() {
    p = new QtJieba::TokenizerPrivate();
}

QStringList Tokenizer::cut(const QString &text) {
    return p->cut(text);
}

Tokenizer::~Tokenizer() {
    delete p;
}
