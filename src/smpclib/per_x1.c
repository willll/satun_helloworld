/****************************************
*			include files				*
****************************************/
#include	"per_x.h"

/****************************************
*		declare private objects			*
****************************************/
static trigger_t	GetTriggerDigital( const SysDevice	*device );
static trigger_t	GetTriggerAnalog( const SysDevice	*device );
static trigger_t	GetTriggerPointer( const SysDevice	*device );
static trigger_t	GetTriggerKeyboard( const SysDevice	*device );
static trigger_t	GetTriggerMD3B( const SysDevice	*device );
static trigger_t	GetTriggerMD6B( const SysDevice	*device );
static trigger_t	GetTriggerMDMouse( const SysDevice	*device );
static trigger_t	GetTriggerUnknown( const SysDevice	*device );

static trigger_handler_t	GetTrigger[] = {
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerDigital, GetTriggerDigital,
	GetTriggerDigital, GetTriggerDigital, GetTriggerDigital, GetTriggerDigital,
	GetTriggerDigital, GetTriggerDigital, GetTriggerDigital, GetTriggerDigital,
	GetTriggerDigital, GetTriggerDigital, GetTriggerDigital, GetTriggerDigital,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerAnalog, GetTriggerAnalog,
	GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog,
	GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog,
	GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog, GetTriggerAnalog,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerPointer, GetTriggerPointer,
	GetTriggerPointer, GetTriggerPointer, GetTriggerPointer, GetTriggerPointer,
	GetTriggerPointer, GetTriggerPointer, GetTriggerPointer, GetTriggerPointer,
	GetTriggerPointer, GetTriggerPointer, GetTriggerPointer, GetTriggerPointer,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerKeyboard, GetTriggerKeyboard,
	GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard,
	GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard,
	GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard, GetTriggerKeyboard,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerMD3B, GetTriggerMD6B, GetTriggerMDMouse,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
	GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown, GetTriggerUnknown,
};

/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		PER_SetTriggerHandler( id, handler );							*
*																		*
*		�w��̂h�c�����y���t�F�����p�̃g���K�n���h����ݒ肵�܂��B	*
*																		*
*				�E�E�E�E�E												*
*		�����ł́u�w��̂h�c�����f�o�C�X�p�̃n���h����ݒ肵�Ă���v	*
*		�Ƃ������Ƃɒ��ڂ��Ă��������B�u�w��̃^�C�v�v�ł͂���܂���	*
*		�̂ŁA���ӂ��Ă��������B										*
*																		*
*		�����Őݒ肵���֐��i�n���h���j�́APER_GetTrigger() �Ɏw���		*
*		�h�c�����f�o�C�X��񂪓n���ꂽ�Ƃ��ɁA�R�[������܂��B		*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		int					id;											*
*		trigger_handler_t	handler;									*
*																		*
*		<id> �́A�T�^�[���y���t�F�����h�c								*
*		<handler> �́A�g���K�n���h��									*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		�Ȃ�															*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		GetTrigger	influence	�g���K�n���h���̃e�[�u��				*
*																		*
*																		*
************************************************************************/
void	PER_SetTriggerHandler( int	id, trigger_handler_t	handler ){
	GetTrigger[id] = handler;
}

/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		handler = PER_GetTriggerHandler( id );							*
*																		*
*		�w��̂h�c�����y���t�F�����p�̃g���K�n���h���𓾂܂��B		*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		int		id;														*
*																		*
*		�T�^�[���y���t�F�����h�c										*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_handler_t	handler;									*
*																		*
*		�g���K�n���h��													*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		GetTrigger	reference	�g���K�n���h���̃e�[�u��				*
*																		*
*																		*
************************************************************************/
trigger_handler_t	PER_GetTriggerHandler( int	id ){
	return	GetTrigger[id];
}

/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerDigital( &device );							*
*																		*
*		�f�W�^���f�o�C�X����g���K���𓾂܂��B						*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerDigital( const SysDevice	*device ){
	const SysDevDigital	*this = ( const SysDevDigital * )device;
	
	trigger_t	data_l = ( trigger_t )( ~this->data[1] ) & 0x00ff;
	trigger_t	data_h = ( trigger_t )( ~this->data[0] ) & 0x00ff;
	
	return	( trigger_t )(( data_h << 8 ) | data_l );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerAnalog( &device );							*
*																		*
*		�A�i���O�f�o�C�X����g���K���𓾂܂��B						*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerAnalog( const SysDevice	*device ){
	const SysDevAnalog	*this = ( const SysDevAnalog * )device;
	
	trigger_t	data_l = ( trigger_t )( ~this->data[1] ) & 0x00ff;
	trigger_t	data_h = ( trigger_t )( ~this->data[0] ) & 0x00ff;
	
	return	( trigger_t )(( data_h << 8 ) | data_l );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerPointer( &device );							*
*																		*
*		�|�C���e�B���O�f�o�C�X����g���K���𓾂܂��B					*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerPointer( const SysDevice	*device ){
	const SysDevPointer	*this = ( const SysDevPointer * )device;
	
	trigger_t	data_h = ( trigger_t )( this->status & PT_TRIGGER );
	
	return	( trigger_t )( data_h << 8 );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerKeyboard( &device );						*
*																		*
*		�L�[�{�[�h�f�o�C�X����g���K���𓾂܂��B						*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerKeyboard( const SysDevice	*device ){
	const SysDevKeyboard	*this = ( const SysDevKeyboard * )device;
	
	trigger_t	data_l = ( trigger_t )( ~this->data[1] ) & 0x00ff;
	trigger_t	data_h = ( trigger_t )( ~this->data[0] ) & 0x00ff;
	
	return	( trigger_t )(( data_h << 8 ) | data_l );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerMD3B( &device );							*
*																		*
*		���K�h���C�u�p�R�{�^���p�b�h����g���K���𓾂܂��B			*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerMD3B( const SysDevice	*device ){
	const struct DevMD3B	*this = ( const struct DevMD3B * )device;
	
	trigger_t	data_h = ( trigger_t )( ~this->data[0] ) & 0x00ff;
	
	return	( trigger_t )( data_h << 8 );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerMD6B( &device );							*
*																		*
*		���K�h���C�u�p�U�{�^���p�b�h����g���K���𓾂܂��B			*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerMD6B( const SysDevice	*device ){
	const struct DevMD6B	*this = ( const struct DevMD6B * )device;
	
	trigger_t	data_l = ( trigger_t )( ~this->data[1] ) & 0x00ff;
	trigger_t	data_h = ( trigger_t )( ~this->data[0] ) & 0x00ff;
	
	return	( trigger_t )(( data_h << 8 ) | data_l );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerMDMouse( &device );							*
*																		*
*		���K�h���C�u�p�}�E�X�i�Ȃ����A�T�^�[���p�̃V���g���}�E�X���j	*
*		����g���K���𓾂܂��B										*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerMDMouse( const SysDevice	*device ){
	const struct DevMDMouse	*this = ( const struct DevMDMouse * )device;
	
	trigger_t	data_h = ( trigger_t )( this->status & PT_TRIGGER );
	
	return	( trigger_t )( data_h << 8 );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		trigger = GetTriggerUnknown( &device );							*
*																		*
*		�s���ȃf�o�C�X����g���K���𓾂܂��B							*
*																		*
*		��� 0 ��Ԃ��܂��B												*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		��� 0 ��Ԃ��܂��B												*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
static trigger_t	GetTriggerUnknown( const SysDevice	*device ){
	return	0;
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		trigger = PER_GetTrigger( device );								*
*																		*
*		�f�o�C�X�̎�ނɉ����ăg���K���𓾂܂��B						*
*																		*
*		PER_SetTriggerHandler() �ɂ���ēo�^����Ă���h�c�����f�o	*
*		�C�X����g���K�������o���ɂ́A������ PER_SetTriggerHandler()*
*		�ɂ���ēo�^����Ă���֐��i�n���h���j��p���܂��B����������	*
*		���̂��Ȃ��ꍇ�ɂ́A�f�t�H���g�ŗp�ӂ���Ă���֐��i�n���h���j	*
*		��p���܂��B���̏ꍇ�A�\�ߑΉ����Ă�����̓y���t�F�����͉��L	*
*		�̂��̂����ł��̂ŁA����ȊO�̓��̓y���t�F��������g���K���	*
*		�𓾂����ꍇ�ɂ́APER_SetTriggerHandler() ���g�p���Ă��������B	*
*																		*
*		�f�t�H���g�őΉ����Ă�����̓y���t�F����						*
*		�f�W�^���f�o�C�X												*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0x02 - 0x0f ��Ԃ�����		*
*		�A�i���O�f�o�C�X												*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0x12 - 0x1f ��Ԃ�����		*
*		�|�C���e�B���O�f�o�C�X											*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0x22 - 0x2f ��Ԃ�����		*
*		�L�[�{�[�h�f�o�C�X												*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0x33 - 0x3f ��Ԃ�����		*
*		���K�h���C�u�p�R�a�p�b�h										*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0xe1 ��Ԃ�����				*
*		���K�h���C�u�p�U�a�p�b�h										*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0xe2 ��Ԃ�����				*
*		���K�h���C�u�p�}�E�X											*
*			�T�^�[���y���t�F�����h�c�Ƃ��� 0xe3 ��Ԃ�����				*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevice	*device;										*
*																		*
*		�f�o�C�X���													*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	trigger;											*
*																		*
*		�g���K����Ԃ��܂��B											*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
trigger_t	PER_GetTrigger( const SysDevice	*this ){
	trigger_t	trigger = 0;
	
	if( this != NULL ){
		int					id = PER_GetID( this );
		trigger_handler_t	handler = PER_GetTriggerHandler( id );
		
		if( handler != NULL )
			trigger = handler( this );
	}
	
	return	trigger;
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		edge = PER_GetEdge( t1, t2 );									*
*																		*
*		�g���K�̃G�b�W���𓾂܂��B									*
*																		*
*		�G�b�W���Ƃ� <t1> �� <t2> �̂Q�̃^�C�~���O�̂������ŕω�	*
*		�����g���K�̏��̂��Ƃ������܂��B								*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		trigger_t	t1;													*
*		trigger_t	t2;													*
*																		*
*		<t1> �� <t2> �̓g���K���B										*
*		<t1> �� <t2> �̎��ԓI�ȏ����͖₢�܂���B						*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	edge;												*
*																		*
*		�g���K�̃G�b�W����Ԃ��܂��B									*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
trigger_t	PER_GetEdge( trigger_t	t1, trigger_t	t2 ){
	return	( trigger_t )( t1 ^ t2 );
}
/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		edge = PER_GetPressEdge( prev, current );						*
*																		*
*		�g���K�̃v���X�G�b�W�i�����G�b�W�j���𓾂܂��B				*
*																		*
*		�v���X�G�b�W���Ƃ� <prev> �� <current> �̂Q�̃^�C�~���O		*
*		�̂������Ƀ����[�X��Ԃ���v���X��Ԃɕω������g���K�̏���	*
*		���Ƃ������܂��B												*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		trigger_t	prev;												*
*		trigger_t	current;											*
*																		*
*		<prev> �� <current> �͋��Ƀg���K���B							*
*		���ԓI�Ɂi <prev> �� <current> �j�Ƃ����֌W�����҂��Ă��܂��B	*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	edge;												*
*																		*
*		�g���K�̃v���X�G�b�W����Ԃ��܂��B							*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
trigger_t	PER_GetPressEdge( trigger_t	prev, trigger_t	current ){
	trigger_t	edge = PER_GetEdge( prev, current );
	
	return	( trigger_t )( current & edge );
}

/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		edge = PER_GetReleaseEdge( prev, current );						*
*																		*
*		�g���K�̃����[�X�G�b�W�i����G�b�W�j���𓾂܂��B				*
*																		*
*		�����[�X�G�b�W���Ƃ� <prev> �� <current> �̂Q�̃^�C�~��		*
*		�O�̂������Ƀv���X��Ԃ��烊���[�X��Ԃɕω������g���K�̏��	*
*		�̂��Ƃ������܂��B												*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		trigger_t	prev;												*
*		trigger_t	current;											*
*																		*
*		<prev> �� <current> �͋��Ƀg���K���B							*
*		���ԓI�Ɂi <prev> �� <current> �j�Ƃ����֌W�����҂��Ă��܂��B	*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		trigger_t	edge;												*
*																		*
*		�g���K�̃����[�X�G�b�W����Ԃ��܂��B							*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
trigger_t	PER_GetReleaseEdge( trigger_t	prev, trigger_t	current ){
	trigger_t	edge = PER_GetEdge( prev, current );
	
	return	( trigger_t )( ~current & edge );
}

#define	ANALOG_ILLEGAL	0xff
#define	ANALOG_ORIGIN	0x7f

/*@*/
/************************************************************************
*																		*
*	�ysynopsis�z														*
*																		*
*		#include	"per_x.h"											*
*																		*
*		PER_GetAnalogXYZ( analog, &x, &y, &z );							*
*																		*
*		�A�i���O�f�o�C�X����w�x�y�����̂`�^�c�R���o�[�^�̏o�͒l��	*
*		�܂��B															*
*																		*
*																		*
*	�yparameters�z														*
*																		*
*		const SysDevAnalog	*analog;									*
*		int		*x;														*
*		int		*y;														*
*		int		*z;														*
*																		*
*		<analog> �̓A�i���O�f�o�C�X���B								*
*		<x> <y> <z> �͂��ꂼ��w�x�y�����̂`�^�c�R���o�[�^�̏o�͒l�B	*
*																		*
*		<x> <y> <z> �� NULL ��n���Ƃ����ɂ͉����Ԃ���܂���B			*
*																		*
*		<x> �ɂ́i�E�j-127 �` +127�i���j���Ԃ���܂��B					*
*		<y> �ɂ́i��j-127 �` +127�i���j���Ԃ���܂��B					*
*		<z> �ɂ́i���j-127 �` +127�i��j���Ԃ���܂��B					*
*																		*
*																		*
*	�yreturn value�z													*
*																		*
*		�Ȃ�															*
*																		*
*																		*
*	�yinfluence/reference objects�z										*
*																		*
*		�Ȃ�															*
*																		*
*																		*
************************************************************************/
void	PER_GetAnalogXYZ( const SysDevAnalog	*this, int	*x, int	*y, int	*z ){
	int		ax = 0;
	int		ay = 0;
	int		az = 0;
	
	if( this->ax != ANALOG_ILLEGAL )
		ax = ( int )this->ax - ANALOG_ORIGIN;
	if( this->ay != ANALOG_ILLEGAL )
		ay = ( int )this->ay - ANALOG_ORIGIN;
	if( this->az != ANALOG_ILLEGAL )
		az = ( int )this->az - ANALOG_ORIGIN;
	
	if( x != NULL )
		*x = ax;
	if( y != NULL )
		*y = ay;
	if( z != NULL )
		*z = az;
}

