/*
**��PER_X.H
**	�y���t�F�������C�u�����̍������h�^�e���C�u����
**	
**	PER_OpenPort()
**		�y���t�F�������C�u����������������B
**	PER_GetPort()
**		�y���t�F�����f�[�^�����W����B
**		�i V-BLANK-OUT ���荞�݃n���h���̒��ŃR�[�����邱�ƁB�j
**	PER_GetDeviceA()
**		���W�����y���t�F�����f�[�^����f�o�C�X���𓾂�B�i��Έʒu�w��j
**	PER_GetDeviceR()
**		���W�����y���t�F�����f�[�^����f�o�C�X���𓾂�B�i���Έʒu�w��j
**	
**	SysPort
**		�y���t�F�������
**	
**	
**	���L�̂R�̒萔�̒l��K�X�ύX���A�ăR���p�C�����Ďg�p���Ă��������B
**	_MAX_PORT
**		�r�`�s�t�q�m�{�̂ɂ��Ă���[�q�̐�
**		�i�ʏ�́A2 �ɐݒ肵�Ă����j
**	_MAX_PERIPHERAL
**		�P�̒[�q�ɐڑ��\�ȃy���t�F�����̐�
**		�i�ʏ�́A�}���`�^�[�~�i���ɑΉ����邽�߂� 6 �ȏ�ɐݒ肵�Ă����j
**	SZ_PERIPHERAL
**		�P�̃y���t�F�����̃f�[�^�T�C�Y�̍ő�
**	
**	SZ_BUFFER
**		�y���t�F�������C�u�������g�p���郏�[�N�G���A�̃T�C�Y�ł��B
*/
#if	!defined( __PER_X_H )
	#define	__PER_X_H
	
	/****************************************
	*			include files				*
	****************************************/
	#include	"sega_xpt.h"
	#include	"sega_per.h"
	
	#include	"per_dev.h"
	#include	"per_dgt.h"
	#include	"per_anlg.h"
	#include	"per_poin.h"
	#include	"per_kbrd.h"
	#include	"per_md.h"
	#include	"per_trg.h"
	
	/****************************************
	*			define constants			*
	****************************************/
	#define	EXIT_SUCCESS	0
	
	#define	_MAX_PORT		2
	#define	_MAX_PERIPHERAL	6
	#define	SZ_PERIPHERAL	5
	#define	SZ_BUFFER		((_MAX_PORT*_MAX_PERIPHERAL*(SZ_PERIPHERAL+2)*2)+SZ_PERIPHERAL)
	
	#define	PID_GUN		0x0a
	
	#define	MID_GUN		0xa0
	
	#define	PER_LOCK	0x00000001
	
	/****************************************
	*		declare object types			*
	****************************************/
	typedef	Uint8	SysPeripheral[SZ_PERIPHERAL+2];
	
	typedef	struct	SysPort	{
		Uint8			id;
		Uint8			connectable;
		SysPeripheral	*peripheral;
	} SysPort;
	
	/****************************************
	*			declare functions			*
	****************************************/
	#if	!defined( __GNUC__ )
		#define	inline
	#endif
	
	static inline int	PER_GetPortID( SysPort	*port ){
		return	( int )( port->id >> 4 );
	}
	
	SysPort		*PER_OpenPort( void );
	void		PER_GetPort( SysPort	*port );
	const SysDevice	*PER_GetDeviceA( const SysPort	*port, Uint32	n );
	const SysDevice	*PER_GetDeviceR( const SysPort	*port, Uint32	n );
	
#endif

