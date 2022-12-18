/*
**��PER_KBRD.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i�L�[�{�[�h�f�o�C�X�p�j
**	
**	PER_GetKeyboardType()
**		�W���L�[�{�[�h�f�o�C�X�̃^�C�v�𓾂�B
**	
**	SysDevKeyboard
**		�T�^�[���W���L�[�{�[�h�f�o�C�X
*/
#if	!defined( __PER_KBRD_H )
	#define	__PER_KBRD_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*			define constants			*
	****************************************/
	/*	�L�[�{�[�h�^�C�v		*/
	#define	KB_TYPE		0x07
	#define	KB_UNKNOWN	0x07
	
	/*	SysDevKeyboard.shift	*/
	#define	K_CAPS		0x40
	#define	K_NUM		0x20
	#define	K_SCROLL	0x10
	#define	K_MAKE		0x08
	#define	K_BREAK		0x01
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��SysDevKeyboard
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_KEYBOARD�j
	**	.size
	**		�g���f�[�^
	**	.data[]
	**		�g���K���A�L�[�{�[�h�^�C�v�B
	**	.shift
	**		�V�t�g�L�[���iK_CAPS,K_NUM,K_SCROLL,K_BREAK,K_MAKE�j
	**	.c
	**		�����i���o�[
	**	.expended[]
	**		�g���f�[�^
	*/
	typedef	struct	SysDevKeyboard	{
		Uint8	type;
		Uint8	size;
		Uint8	data[2];
		Uint8	shift;
		Uint8	c;
		Uint8	expanded[1];
	} SysDevKeyboard;
	
	/****************************************
	*			declare functions			*
	****************************************/
	#if	!defined( __GNUC__ )
		#define	inline
	#endif
	
	static inline int	PER_GetKeyboardType( const SysDevKeyboard	*this ){
		return	( int )( this->data[1] & KB_TYPE );
	}
	
#endif

