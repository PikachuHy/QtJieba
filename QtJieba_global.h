//
// Created by pikachu on 5/19/2021.
//

#ifndef QTJIEBA_QTJIEBA_GLOBAL_H
#define QTJIEBA_QTJIEBA_GLOBAL_H
#if defined(QtJieba_LIBRARY)
#  define QTJIEBASHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTJIEBASHARED_EXPORT Q_DECL_IMPORT
#endif
#endif //QTJIEBA_QTJIEBA_GLOBAL_H
