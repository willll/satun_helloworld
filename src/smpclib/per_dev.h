/*
**��PER_DEV.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u����
**	
**	PER_GetID()
**		�T�^�[���y���t�F�����h�c�𓾂�B
**	PER_GetType()
**		�y���t�F�����^�C�v�𓾂�B
**	PER_GetSize()
**		�y���t�F�����f�[�^�̃T�C�Y�𓾂�B
**	
**	SysDevice
**		�T�^�[���W���y���t�F�����̊�{�^
*/
#if	!defined( __PER_DEV_H )
	#define	__PER_DEV_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*			define constants			*
	****************************************/
	/*	�T�^�[���y���t�F�����h�c	*/
	#define	ID_UNCONNECTED	0xff
	#define	ID_MD3B			0xe1
	#define	ID_MD6B			0xe2
	#define	ID_MDMOUSE		0xe3
	#define	ID_DIGITAL		0x02
	#define	ID_RACING		0x13
	#define	ID_ANALOG		0x15
	#define	ID_MOUSE		0x23
	#define	ID_KEYBOARD		0x34
	#define	ID_GUN			0xfa
	
	#define	ID_TYPE			0xf0
	#define	ID_SIZE			0x0f
	
	/*	�T�^�[���y���t�F�����^�C�v	*/
	#define	TYPE_DIGITAL	0x00
	#define	TYPE_ANALOG		0x10
	#define	TYPE_POINTER	0x20
	#define	TYPE_KEYBOARD	0x30
	#define	TYPE_MD			0xe0
	#define	TYPE_UNKNOWN	0xf0
	
	/*	�o�[�`���K���̃g���K���	*/
	#define	GUN_START		0x20
	#define	GUN_TRIGGER		0x10
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��SysDevice
	**	.type
	**		�T�^�[���y���t�F�����^�C�v
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y
	**	.data[]
	**		�f�[�^
	*/
	typedef	struct	SysDevice	{
		Uint8	type;
		Uint8	size;
		Uint8	data[1];
	} SysDevice;
	
	/****************************************
	*			declare functions			*
	****************************************/
	#if	!defined( __GNUC__ )
		#define	inline
	#endif
	
	static inline int	PER_GetType( const SysDevice	*this ){
		return	( int )this->type;
	}
	static inline int	PER_GetSize( const SysDevice	*this ){
		int		size = 0;
		
		if( PER_GetType( this ) != TYPE_UNKNOWN )
			size = ( int )this->size;
		
		return	size;
	}
	static inline int	PER_GetID( const SysDevice	*this ){
		return	( int )( this->type | this->size );
	}
	
#endif

