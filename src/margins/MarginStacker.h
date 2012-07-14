#ifndef MARGINSTACKER_H
#define MARGINSTACKER_H

#include <QWidget>

class QodeEdit;

class MarginStacker : public QWidget
{
    Q_OBJECT
    
public:
    // the order is important as it defined the default presentation order of the margins
    enum Type {
        Invalid = -1,
        LineBookmark = 0, // wip
        LineNumber = 1, // done
        CodeFolding = 2,
        LineRevision = 3, // done
        Spacing = 4, // done
    };
    
    MarginStacker( QodeEdit* editor = 0 );
    virtual ~MarginStacker();
    
    QodeEdit* editor() const;
    void setEditor( QodeEdit* editor );
    
    bool isVisible( MarginStacker::Type type ) const;
    void setVisible( MarginStacker::Type type, bool visible = true );
    
public slots:
    void updateLayout();

protected:
    virtual bool eventFilter( QObject* object, QEvent* event );

private:
    class Private;
    MarginStacker::Private* d;
};

#endif // MARGINSTACKER_H
