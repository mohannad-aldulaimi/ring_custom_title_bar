load "cutomtitlebar.ring"
load "guilib.ring"

new qApp{

    win = new qwidget({
        resize(400,300)
        new CustomTitleBar(win,"Custom Title Bar"){
            setMenuBar(new qMenuBar(){
                new qMenu("File"){
                    new qAction("New")
                    new qAction("Open")
                    new qAction("Save")
                    new qAction("Save As")
                    new qAction("Exit")
                }
                new qMenu("Edit"){
                    new qAction("Undo")
                    new qAction("Redo")
                    new qAction("Cut")
                    new qAction("Copy")
                    new qAction("Paste")
                }
                new qMenu("Help"){
                    new qAction("About")
                }
            })
        }
    }
    exec()
}