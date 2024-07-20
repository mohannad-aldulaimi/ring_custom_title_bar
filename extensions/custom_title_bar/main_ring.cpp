#include "main.hpp"
extern "C"{
#include "ring.h"
}

RING_FUNC(ring_CustomTitleBar_setLogoMovie)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLogoMovie((QMovie *) RING_API_GETCPOINTER(2,"QMovie"));
}


RING_FUNC(ring_CustomTitleBar_setLogoPixmap)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	pObject->setLogoPixmap(* (QPixmap  *) RING_API_GETCPOINTER(2,"QPixmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPixmap"));
}


RING_FUNC(ring_CustomTitleBar_setMenuBar)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMenuBar((QMenuBar *) RING_API_GETCPOINTER(2,"QMenuBar"));
}


RING_FUNC(ring_CustomTitleBar_unsetMenuBar)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	pObject->unsetMenuBar();
}


RING_FUNC(ring_CustomTitleBar_setTitleAlignment)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	pObject->setTitleAlignment(* (Qt::Alignment  *) RING_API_GETCPOINTER(2,"Qt::Alignment"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Qt::Alignment"));
}


RING_FUNC(ring_CustomTitleBar_setMenuBarAlignment)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	pObject->setMenuBarAlignment(* (Qt::Alignment  *) RING_API_GETCPOINTER(2,"Qt::Alignment"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Qt::Alignment"));
}


RING_FUNC(ring_CustomTitleBar_setButtonsAlignment)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	pObject->setButtonsAlignment(* (Qt::Alignment  *) RING_API_GETCPOINTER(2,"Qt::Alignment"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Qt::Alignment"));
}


RING_FUNC(ring_CustomTitleBar_getMinimizeButton)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	RING_API_RETCPOINTER(pObject->getMinimizeButton(),"QPushButton");
}


RING_FUNC(ring_CustomTitleBar_getMaximizeButton)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	RING_API_RETCPOINTER(pObject->getMaximizeButton(),"QPushButton");
}


RING_FUNC(ring_CustomTitleBar_getCloseButton)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	RING_API_RETCPOINTER(pObject->getCloseButton(),"QPushButton");
}


RING_FUNC(ring_CustomTitleBar_getMenuBar)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	RING_API_RETCPOINTER(pObject->getMenuBar(),"QMenuBar");
}


RING_FUNC(ring_CustomTitleBar_getLogo)
{
	CustomTitleBar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
	RING_API_RETCPOINTER(pObject->getLogo(),"QLabel");
}

RING_FUNC(ring_CustomTitleBar_new)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {

		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	CustomTitleBar *pObject = new CustomTitleBar((QWidget *) RING_API_GETCPOINTER(1,"QWidget"),RING_API_GETSTRING(2));
	RING_API_RETCPOINTER(pObject,"CustomTitleBar");
}

RING_FUNC(ring_CustomTitleBar_delete)
{
	CustomTitleBar *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (CustomTitleBar *) RING_API_GETCPOINTER(1,"CustomTitleBar");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}
extern "C"{
RING_LIBINIT
{
	RING_API_REGISTER("customtitlebar_setlogomovie",ring_CustomTitleBar_setLogoMovie);
	RING_API_REGISTER("customtitlebar_setlogopixmap",ring_CustomTitleBar_setLogoPixmap);
	RING_API_REGISTER("customtitlebar_setmenubar",ring_CustomTitleBar_setMenuBar);
	RING_API_REGISTER("customtitlebar_unsetmenubar",ring_CustomTitleBar_unsetMenuBar);
	RING_API_REGISTER("customtitlebar_settitlealignment",ring_CustomTitleBar_setTitleAlignment);
	RING_API_REGISTER("customtitlebar_setmenubaralignment",ring_CustomTitleBar_setMenuBarAlignment);
	RING_API_REGISTER("customtitlebar_setbuttonsalignment",ring_CustomTitleBar_setButtonsAlignment);
	RING_API_REGISTER("customtitlebar_getminimizebutton",ring_CustomTitleBar_getMinimizeButton);
	RING_API_REGISTER("customtitlebar_getmaximizebutton",ring_CustomTitleBar_getMaximizeButton);
	RING_API_REGISTER("customtitlebar_getclosebutton",ring_CustomTitleBar_getCloseButton);
	RING_API_REGISTER("customtitlebar_getmenubar",ring_CustomTitleBar_getMenuBar);
	RING_API_REGISTER("customtitlebar_getlogo",ring_CustomTitleBar_getLogo);
	RING_API_REGISTER("customtitlebar_new",ring_CustomTitleBar_new);
	RING_API_REGISTER("customtitlebar_delete",ring_CustomTitleBar_delete);
}
}