/*
**��PER_POIN.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i�|�C���e�B���O�f�o�C�X�p�j
**	
**	PER_GetPointerXY()
**		�W���|�C���e�B���O�f�o�C�X�̈ړ��ʂ𓾂�B
**	
**	SysDevPointer
**		�T�^�[���W���|�C���e�B���O�f�o�C�X
*/
#if	!defined( __PER_POIN_H )
	#define	__PER_POIN_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*			define constants			*
	****************************************/
	/*	SysDevPointer.status	*/
	#define	PT_OVER_Y	0x80
	#define	PT_OVER_X	0x40
	#define	PT_SIGN_Y	0x20
	#define	PT_SIGN_X	0x10
	#define	PT_START	0x08
	#define	PT_MIDDLE	0x04
	#define	PT_RIGHT	0x02
	#define	PT_LEFT		0x01
	#define	PT_TRIGGER	0x0f
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��SysDevPointer
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_POINTER�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y
	**	.status
	**		�g���K���A�ړ��ʂ̕����A�ړ��ʂ̃I�[�o�[�t���[�B
	**	.dx
	**	.dy
	**		�w�x�����̈ړ��ʂ̐�Βl�i0�`255�j
	**	.expended[]
	**		�g���f�[�^
	*/
	typedef	struct	SysDevPointer	{
		Uint8	type;
		Uint8	size;
		Uint8	status;
		Uint8	dx;
		Uint8	dy;
		Uint8	expanded[1];
	} SysDevPointer;
	
	/****************************************
	*			declare functions			*
	****************************************/
	#if	!defined( __GNUC__ )
		#define	inline
	#endif
	
	static inline void	PER_GetPointerXY( const SysDevPointer	*this, int	*dx, int	*dy ){
		if( dx != NULL )
			*dx = ( int )( signed char )this->dx;
		if( dy != NULL )
			*dy = -( int )( signed char )this->dy;
	}
	
#endif

