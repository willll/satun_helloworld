/*
**��PER_MD.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i���K�h���C�u�p�y���t�F�����p�j
**	
**	DevMD3B
**		���K�h���C�u�E�R�{�^���p�b�h
**	DevMD6B
**		���K�h���C�u�E�U�{�^���p�b�h
**	DevMDMouse
**		���K�h���C�u�E�}�E�X
*/
#if	!defined( __PER_MD_H )
	#define	__PER_MD_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	
	/****************************************
	*		declare object types			*
	****************************************/
	/*
	**��DevMD3B
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_MD�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y�i==1�j
	**	.data[]
	**		�g���K���
	*/
	struct	DevMD3B	{
		Uint8	type;
		Uint8	size;
		Uint8	data[1];
	};
	
	/*
	**��DevMD6B
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_MD�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y�i==2�j
	**	.data[]
	**		�g���K���
	*/
	struct	DevMD6B	{
		Uint8	type;
		Uint8	size;
		Uint8	data[2];
	};
	
	/*
	**��DevMDMouse
	**	.type
	**		�T�^�[���y���t�F�����^�C�v�i==TYPE_MD�j
	**	.size
	**		�y���t�F�����f�[�^�T�C�Y�i==3�j
	**	.status
	**		�g���K���A�ړ��ʂ̕����A�ړ��ʂ̃I�[�o�[�t���[�B
	**	.dx
	**	.dy
	**		�w�x�����̈ړ��ʂ̐�Βl�i0�`255�j
	*/
	struct	DevMDMouse	{
		Uint8	type;
		Uint8	size;
		Uint8	status;
		Uint8	dx;
		Uint8	dy;
	};
	
#endif

