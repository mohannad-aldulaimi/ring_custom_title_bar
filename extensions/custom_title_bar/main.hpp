#ifndef CUSTOMTITLEBAR_HPP
#define CUSTOMTITLEBAR_HPP

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QApplication>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMainWindow>

#define cStyleSheet_btns "QPushButton {background-color: #2d2d2d; color: white; border: none; border-radius:10px;font-size:15px; text-align: center; padding-bottom: 0.5em; } QPushButton:hover { background-color: #ff0000; }"
#define cStyleSheet_close_btn "QPushButton {background-color: #2d2d2d; color: white; border: none; border-radius:10px;font-size:20px; text-align: center;} QPushButton:hover { background-color: red; }"
#define cStyleSheet_maximize_btn "QPushButton {background-color: #2d2d2d; color: white; border: none; border-radius:10px;font-size:20px; text-align: center;padding-bottom: 0.3em; } QPushButton:hover { background-color: #0000ff; }"
#define cStyleSheet_minimize_btn "QPushButton {background-color: #2d2d2d; color: white; border: none; border-radius:10px;font-size:20px; text-align: center;padding-bottom: 0.5em; } QPushButton:hover { background-color: #00ff00;color:#000000; }"

class CustomTitleBar : public QWidget {
    Q_OBJECT

public:
    explicit CustomTitleBar(QWidget *parent = nullptr, const char *cWindowTitle = "Test Title", QMenuBar *pMenubar = nullptr)
        : QWidget(parent), mousePressed(false), menubar(nullptr), logo(nullptr) {

        bool isQMainWindow = qobject_cast<QMainWindow *>(parent) != nullptr;

        // Adjust parent layout
        if (isQMainWindow) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow *>(parent);
            if (!mainWindow->centralWidget()) {
                QWidget *centralWidget = new QWidget(parent);
                mainWindow->setCentralWidget(centralWidget);
            }
        }

        QWidget *centralWidget = isQMainWindow ? qobject_cast<QMainWindow *>(parent)->centralWidget() : parent;

        QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout *>(centralWidget->layout());
        if (!mainLayout) {
            mainLayout = new QVBoxLayout(centralWidget);
            mainLayout->setContentsMargins(0, 0, 0, 0);
            mainLayout->setSpacing(0);
            centralWidget->setLayout(mainLayout);
        }

        parent->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

        mainLayout->insertWidget(0, this);

        setFixedHeight(50);

        title = new QLabel(cWindowTitle, this);
        QFont font("Lucida Calligraphy", 20); 
        title->setFont(font);
        title->setStyleSheet("QLabel {padding: 8px;padding-bottom: 0.1em; }");
        
        minimizeButton = new QPushButton("_", this);
        minimizeButton->setFixedSize(40, 40);
        minimizeButton->setStyleSheet(cStyleSheet_minimize_btn);
        
        maximizeButton = new QPushButton("🗖", this);
        maximizeButton->setFixedSize(40, 40);
        maximizeButton->setStyleSheet(cStyleSheet_maximize_btn);
        
        closeButton = new QPushButton("X", this);
        closeButton->setFixedSize(40, 40);
        closeButton->setStyleSheet(cStyleSheet_close_btn);
        
        // Connect button signals to slots
        connect(minimizeButton, &QPushButton::clicked, [parent]() { parent->showMinimized(); });
        connect(maximizeButton, &QPushButton::clicked, [parent]() {
            if (parent->isMaximized()) {
                parent->showNormal();
            } else {
                parent->showMaximized();
            }
        });
        connect(closeButton, &QPushButton::clicked, [parent]() { parent->close(); QApplication::quit(); });

        // Arrange top bar widgets
        topBarLayout = new QHBoxLayout(this);
        topBarLayout->setContentsMargins(5, 0, 5, 0);

        logoLayout = new QHBoxLayout();
        titleLayout = new QHBoxLayout();
        menuBarLayout = new QHBoxLayout();
        buttonsLayout = new QHBoxLayout();

        logoLayout->setContentsMargins(0, 0, 0, 0);
        titleLayout->setContentsMargins(0, 0, 0, 0);
        menuBarLayout->setContentsMargins(0, 0, 0, 0);
        buttonsLayout->setContentsMargins(0, 0, 0, 0);

        logoLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        titleLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        menuBarLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        buttonsLayout->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        topBarLayout->addLayout(logoLayout);
        topBarLayout->addLayout(titleLayout);
        topBarLayout->addLayout(menuBarLayout);
        topBarLayout->addStretch();  // Spacer to push buttons to the right
        topBarLayout->addLayout(buttonsLayout);

        titleLayout->addWidget(title);

        buttonsLayout->addWidget(minimizeButton);
        buttonsLayout->addWidget(maximizeButton);
        buttonsLayout->addWidget(closeButton);

        setLayout(topBarLayout);

        if (pMenubar) {
            setMenuBar(pMenubar);
        }
    }

    void setLogoMovie(QMovie *movie) {
        if (!logo) {
            logo = new QLabel(this);
            logoLayout->addWidget(logo);
        }
        logo->setMovie(movie);
    } 

    void setLogoPixmap(QPixmap &pixmap) {
        if (!logo) {
            logo = new QLabel(this);
            logoLayout->addWidget(logo);
        }
        logo->setPixmap(pixmap);
    }

    void setLogoAlignment(Qt::Alignment alignment) {
        if (logo) {
            logoLayout->setAlignment(logo, alignment);
        }
    }

    void setTitleAlignment(Qt::Alignment alignment) {
        titleLayout->setAlignment(title, alignment);
    }

    void setMenuBarAlignment(Qt::Alignment alignment) {
        if (menubar) {
            menuBarLayout->setAlignment(menubar, alignment);
        }
    }

    void setButtonsAlignment(Qt::Alignment alignment) {
        buttonsLayout->setAlignment(minimizeButton, alignment);
        buttonsLayout->setAlignment(maximizeButton, alignment);
        buttonsLayout->setAlignment(closeButton, alignment);
    }

    void unsetLogo() {
        if (logo) {
            logoLayout->removeWidget(logo);
            delete logo;
            logo = nullptr;
        }
    }

    QLabel* getLogo() const {
        return logo;
    }

void setMenuBar(QMenuBar *pMenubar) {
    // Remove the existing menu bar if it exists
    if (menubar) {
        menuBarLayout->removeWidget(menubar);
        menubar->setParent(nullptr); // Unset the parent to avoid any dangling pointers
    }

    // Update the menubar pointer to the new one
    menubar = pMenubar;

    // Add the new menu bar if it is not null
    if (menubar) {
        menuBarLayout->addWidget(menubar);
        menuBarLayout->setAlignment(menubar, Qt::AlignLeft | Qt::AlignVCenter); // Align to the left
    } else {
        menuBarLayout->setAlignment(menubar, Qt::AlignLeft | Qt::AlignVCenter); // Ensure alignment is reset
    }
}


    void unsetMenuBar() {
        if (menubar) {
            menuBarLayout->removeWidget(menubar);
            menubar->setParent(nullptr);
            menubar = nullptr;
        }
    }

    QMenuBar* getMenuBar() const {
        return menubar;
    }

    QPushButton* getMinimizeButton() const {
        return minimizeButton;
    }

    QPushButton* getMaximizeButton() const {
        return maximizeButton;
    }

    QPushButton* getCloseButton() const {
        return closeButton;
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            dragPosition = event->globalPos() - window()->frameGeometry().topLeft();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (mousePressed && (event->buttons() & Qt::LeftButton)) {
            window()->move(event->globalPos() - dragPosition);
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        Q_UNUSED(event)
        mousePressed = false;
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override {
        Q_UNUSED(event)
        if (window()->isMaximized()) {
            window()->showNormal();
        } else {
            window()->showMaximized();
        }
    }

private:
    bool mousePressed;
    QPoint dragPosition;
    QLabel *title;
    QLabel *logo;
    QMenuBar *menubar;
    QPushButton *minimizeButton;
    QPushButton *maximizeButton;
    QPushButton *closeButton;
    QHBoxLayout *topBarLayout;
    QHBoxLayout *logoLayout;
    QHBoxLayout *titleLayout;
    QHBoxLayout *menuBarLayout;
    QHBoxLayout *buttonsLayout;
};

#endif // CUSTOMTITLEBAR_HPP
