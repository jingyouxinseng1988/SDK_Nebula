#pragma once

#include "include/RobotUsbWrapper.h"

#define WM_MSGID(code) (WM_USER+0x200+code)
#define WM_EVTID(code) (code-0x200-WM_USER)

#define WM_RBTEVENT			WM_USER + 1001

class CRbtEventHandler :
	public IRobotEventHandler
{
public:
	CRbtEventHandler(void);
	~CRbtEventHandler(void);

	void SetMsgReceiver(HWND hWnd = NULL);
	HWND GetMsgReceiver() {return m_hMainWnd;};
private:
	//�豸����¼�
	virtual void onDeviceChanged(eDeviceStatus status);
	//����״̬�¼�
	virtual void onGatewayStatus(const ROBOT_STATUS &status);
	//node״̬�¼�
	virtual void onNodeStatus(const ROBOT_STATUS &status);
	//�汾�¼�
	virtual void onDeviceInfo(const ST_DEVICE_INFO &info);
	//����״̬�¼�
	virtual void onOnlineStatus(int *status);
	//��ѡ�����¼�
	virtual void onExitVote(int *status);
	//��ѡ�����¼�
	virtual void onExitVoteMulit(const ST_OPTION_PACKET &packet);
	//���������������¼�
	virtual void onMassData(int index,const PEN_INFO &penInfo);
	//���ش����¼�
	virtual void onGatewayError(int error);
	//�����豸����¼�
	virtual void onSetDeviceNum(int result,int customid, int classid, int deviceid);
	//���������¼�
	virtual void onFirmwareData(int progress);
	//��������¼�
	virtual void onRawResult(int result);
	//�����¼�
	virtual void onGatewayReboot();
	//���������¼�
	virtual void onOriginalPacket(float x,float y,int press,int status);
	//nodeģʽ�¼�
	virtual void onNodeMode(int mode);
	//����rtc�¼�
	virtual void onSetRtc(int result);
	//���������¼�
	virtual void onKeyPress(int result);
	//ҳ����ʾ�¼�
	virtual void onShowPage(int count, int current);
	//���߱ʼ����������¼�
	virtual void onSyncPacket(const PEN_INFO &penInfo);
	//���߱ʼǿ�ʼ
	virtual void onSyncBegin();
	//���߱ʼǽ���
	virtual void onSyncEnd();
	//�ϱ�ҳ��
	virtual void onPageNo(int pageNo);
	//�����¼�
	virtual void onVoteAnswer(int index,int answer);
	//////////////////////////////dongle//////////////////////
	//Dongle״̬�¼�
	virtual void onDongleStatus(int status);
	//Dongle�汾�¼�
	virtual void onDongleVersion(const ST_VERSION &version);
	//Dongleɨ���¼�
	virtual void onDongleScanRes(const ST_BLE_DEVICE &device);
	//slave�汾�¼�
	virtual void onSlaveVersion(int type,const ST_VERSION &version);
	//slave״̬�¼�
	virtual void onSlaveStatus(int status);
	//���������¼�
	virtual void onSetName(uint8_t result);
	//slave�����¼�
	virtual void onSlaveError(int error);

	//�ʼ��Ż����
	virtual void onOut(float x,float y,float width,int press,int status);

private:
	HWND		m_hMainWnd;
};
