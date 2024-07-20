load 'guilib.ring'
loadlib('CustomTitleBar.dll')

class CustomTitleBar from qwidget
        pObject
        func init p1,p2
                pObject=customtitlebar_new(GetObjectPointerFromRingObject(p1),p2)
                return self
        func delete 
                pObject=customtitlebar_delete(pObject)
        func setLogopixmap p1
                customtitlebar_setLogopixmap(pObject, GetObjectPointerFromRingObject(p1) )
        func setLogoMovie p1
                customtitlebar_setLogoMovie(pObject, GetObjectPointerFromRingObject(p1) )
        func unsetLogo
                customtitlebar_unsetlogo(pObject)
        func setMenuBar p1
                customtitlebar_setmenubar(pObject, GetObjectPointerFromRingObject(p1) )
        func unsetMenuBar
                customtitlebar_unsetmenubar(pObject)       
        func getLogo
                pTempObj = new qLabel
		pTempObj.pObject = customtitlebar_getlogo(pObject)
	        return pTempObj
        func getMenuBar
                pTempObj = new qmenubar
		pTempObj.pObject = customtitlebar_getmenubar(pObject)
	        return pTempObj
        func getMinimizeButton
                pTempObj = new QPushButton
		pTempObj.pObject = customtitlebar_getminimizebutton(pObject)
	        return pTempObj
        func getMaximizeButton
                pTempObj = new QPushButton
		pTempObj.pObject = customtitlebar_getmaximizebutton(pObject)
	        return pTempObj
        func getCloseButton
                pTempObj = new QPushButton
		pTempObj.pObject = customtitlebar_getclosebutton(pObject)
	        return pTempObj
