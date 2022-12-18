/*
**��PER_DGT.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i�f�W�^���f�o�C�X�p�j
**	
**	SysDevDigital
**		�T�^�[���W���f�W�^���f�o�C�X
*/
#if	!defined( __PER_DGT_H )
	#define	__PER_DGT_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��SysDevDigital
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_DIGITAL�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y
	**	.data[]
	**		�g���K���
	**	.expended[]
	**		�g���f�[�^
	*/
	typedef	struct	SysDevDigital	{
		Uint8	type;
		Uint8	size;
		Uint8	data[2];
		Uint8	expanded[1];
	} SysDevDigital;
	
#endif

