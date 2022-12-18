/*
**��PER_ANLG.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i�A�i���O�f�o�C�X�p�j
**	
**	PER_GetAnalogXYZ()
**		�W���A�i���O�f�o�C�X�̂`�^�c�R���o�[�^�̏o�͒l�𓾂�B
**	
**	SysDevAnalog
**		�T�^�[���W���A�i���O�f�o�C�X
*/
#if	!defined( __PER_ANLG_H )
	#define	__PER_ANLG_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��SysDevAnalog
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�iTYPE_ANALOG�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y
	**	.data[]
	**		�g���K���
	**	.ax
	**		�w�����̂`�^�c�R���o�[�^�̏o�͒l�i��0�`�E255�j
	**	.ay
	**		�x�����̂`�^�c�R���o�[�^�̏o�͒l�i��0�`��255�j
	**	.az
	**		�y�����̂`�^�c�R���o�[�^�̏o�͒l�i��0�`��255�j
	**	.expended[]
	**		�g���f�[�^
	*/
	typedef	struct	SysDevAnalog	{
		Uint8	type;
		Uint8	size;
		Uint8	data[2];
		Uint8	ax;
		Uint8	ay;
		Uint8	az;
		Uint8	expanded[1];
	} SysDevAnalog;
	
	/****************************************
	*			declare functions			*
	****************************************/
	void	PER_GetAnalogXYZ( const SysDevAnalog	*this, int	*x, int	*y, int	*z );
	
#endif

