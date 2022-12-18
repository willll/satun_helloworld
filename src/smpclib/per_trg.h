/*
**��PER_TRG.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u�����i�g���K���ɂ��āj
**	
**	PER_DisguiseTrigger()
**		�g���K�����A�T�C���e�[�u���ɂ��������ĕϊ�����B
**	
**	PER_GetTrigger()
**		�w�肳�ꂽ�^�C�~���O�ł̃g���K���𓾂�B
**		�i�A�T�C���e�[�u�����w�肳��Ă���΁A����ɂ��������ĕϊ�����j
**	PER_GetEdge()
**		�w�肳�ꂽ�Q�̃^�C�~���O�̊Ԃŕω������g���K���𓾂�B
**	PER_GetPressEdge()
**		�w�肳�ꂽ�Q�̃^�C�~���O�̊Ԃŉ����ꂽ�g���K���𓾂�B
**	PER_GetReleaseEdge()
**		�w�肳�ꂽ�Q�̃^�C�~���O�̊Ԃŕ����ꂽ�g���K���𓾂�B
**	
**	PER_SetTriggerHandler()
**		�w�肳�ꂽ�h�c�����y���t�F�����p�̃g���K�n���h����o�^����B
**	PER_GetTriggerHandler()
**		�w�肳�ꂽ�h�c�����y���t�F�����p�̃g���K�n���h���𓾂�B
**	
**	assigment_t
**		�g���K���ϊ��e�[�u���i�A�T�C���e�[�u���j
**	trigger_t
**		�g���K���
**	trigger_handler_t
**		�g���K�n���h���i�f�o�C�X����g���K�������o�����߂̃n���h���j
*/
#if	!defined( __PER_TRG_H )
	#define	__PER_TRG_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	#include	"sega_per.h"
	
	/****************************************
	*			define constants			*
	****************************************/
	/*
	**��trigger_t
	**	TRG_A       �`�{�^��
	**	TRG_B       �a�{�^��
	**	TRG_C       �b�{�^��
	**	TRG_X       �w�{�^��
	**	TRG_Y       �x�{�^��
	**	TRG_Z       �y�{�^��
	**	TRG_L       �k�{�^��
	**	TRG_R       �q�{�^��
	**	TRG_UP      ��
	**	TRG_DOWN    ��
	**	TRG_LEFT    ��
	**	TRG_RIGHT   ��
	**	TRG_START   �X�^�[�g�{�^��
	**	
	**	�W���|�C���e�B���O�f�o�C�X��  �E  �̃{�^���� TRG_A
	**	�W���|�C���e�B���O�f�o�C�X�̐^�񒆂̃{�^���� TRG_C
	**	�W���|�C���e�B���O�f�o�C�X��  ��  �̃{�^���� TRG_B
	**	�W���|�C���e�B���O�f�o�C�X�ɂ� TRG_START,A,B,C �����Ȃ��B
	**	���K�h���C�u�U�a�p�b�h�̃��[�h�{�^���� TRG_R
	**	���K�h���C�u�U�a�p�b�h�ɂ� TRG_L �͂Ȃ��B
	**	���K�h���C�u�R�a�p�b�h�ɂ� TRG_X,Y,Z,L,R �͂Ȃ��B
	**	���[�V���O�R���g���[���[�ɂ� Y,Z �����̃A�i���O�o�͂͂Ȃ��B
	**	���[�V���O�R���g���[���[�ɂ� TRG_LEFT,RIGHT,L,R �͂Ȃ��B
	**	
	**	TRG_MODE	���K�h���C�u�U�{�^���p�b�h�̃��[�h�{�^��
	**	TRG_RESET	�\�t�g�t�F�A���Z�b�g
	*/
	#define	TRG_B		PER_DGT_B
	#define	TRG_C		PER_DGT_C
	#define	TRG_A		PER_DGT_A
	#define	TRG_START	PER_DGT_S
	#define	TRG_UP		PER_DGT_U
	#define	TRG_DOWN	PER_DGT_D
	#define	TRG_LEFT	PER_DGT_L
	#define	TRG_RIGHT	PER_DGT_R
	#define	TRG_L		PER_DGT_TL
	#define	TRG_Z		PER_DGT_Z
	#define	TRG_Y		PER_DGT_Y
	#define	TRG_X		PER_DGT_X
	#define	TRG_R		PER_DGT_TR
	
	#define	TRG_MODE	TRG_R
	
	#define	TRG_RESET	(TRG_START|TRG_A|TRG_B|TRG_C)
	
	#define	TRIGGER_BIT	16
	
	/****************************************
	*		declare object types			*
	****************************************/
	typedef Uint16	trigger_t;
	
	/*
	**��assignment_t
	**	�����o�̏��Ԃ�ύX���Ă͂����Ȃ��B�����o�̏��Ԃ� trigger_t �p�̒�
	**	�� 'TRG_???' �̃r�b�g���тƑΉ����Ă���B
	*/
	typedef	struct assignment_t	{
		trigger_t	reserved1[3];
		trigger_t	l;
		trigger_t	z;
		trigger_t	y;
		trigger_t	x;
		trigger_t	r;
		trigger_t	b;
		trigger_t	c;
		trigger_t	a;
		trigger_t	start;
		trigger_t	up;
		trigger_t	down;
		trigger_t	left;
		trigger_t	right;
	} assignment_t;
	
	typedef trigger_t	( *trigger_handler_t )( const SysDevice * );
	
	/****************************************
	*			declare functions			*
	****************************************/
	trigger_t	PER_DisguiseTrigger( const assignment_t	*assignment, trigger_t	trigger );
	
	void	PER_SetTriggerHandler( int	id, trigger_handler_t	handler );
	trigger_handler_t	PER_GetTriggerHandler( int	id );
	
	trigger_t	PER_GetTrigger( const SysDevice	*this );
	trigger_t	PER_GetEdge( trigger_t	t1, trigger_t	t2 );
	trigger_t	PER_GetPressEdge( trigger_t	prev, trigger_t	current );
	trigger_t	PER_GetReleaseEdge( trigger_t	prev, trigger_t	current );
	
#endif

