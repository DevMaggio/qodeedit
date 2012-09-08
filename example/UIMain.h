/****************************************************************************
**
**         Created using Monkey Studio IDE v1.9.0.1 (1.9.0.1)
** Authors   : Filipe Azevedo aka Nox P@sNox <pasnox@gmail.com> and The QodeEdit development team
** Project   : QodeEdit
** FileName  : UIMain.h
** Date      : 2012-09-02T23:04:12
** License   : LGPL3
** Comment   : A source code component editor based on QPlainTextEdit/QTextDocument/QSyntaxHighlighter and Kate xml language definition files.
** Home Page : https://github.com/pasnox/qodeedit
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/
#ifndef UIMAIN_H
#define UIMAIN_H

#include <QtGui>

#include "CodeEditor.h"

class Ui_UIMain;

class QodeEditor : public CodeEditor
{
    Q_OBJECT

public:
    QodeEditor( QWidget* parent = 0 );
    
    static QString fileContent( const QString& filePath, const QByteArray& textCodec = QByteArray( "UTF-8" ) );

protected slots:
    void save();
};

Q_DECLARE_METATYPE( QodeEditor* )

class UIMain : public QMainWindow
{
    Q_OBJECT

public:
    UIMain( QWidget* parent = 0 );
    virtual ~UIMain();
    
    void appendDebugMessage( const QString& message );
    
    static void messageHandler( QtMsgType type, const char* msg );
    static UIMain* qMain;
    
protected:
    Ui_UIMain* ui;
    QHash<QString, QodeEditor*> mEditors;
    
    QodeEditor* editor( int row ) const;
    
protected slots:
    void on_lwEditors_currentRowChanged( int row );
    void on_swEditors_currentChanged( int row );
};

#endif // UIMAIN_H