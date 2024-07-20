load "cutomtitlebar.ring"
load "guilib.ring"

new qApp{
    stylefusionBlack()
    win = new qwidget(){
        resize(400,300)
        lbl = new qLabel(win){
            setText("Hello, World!")
            setStyleSheet("font-size: 20px; color: blue;")
        }
        setLayout(new QVBoxLayout(){
            addWidget(lbl)
        })
        new CustomTitleBar(win,"Custom Title Bar"){
            setMenuBar(
                new qMenuBar(win) {
                    addAction("File")
                    addAction("Edit")
                    addAction("View")
                    addAction("Help")
            }
          )
        }
        
        show()
    }
    exec()
}