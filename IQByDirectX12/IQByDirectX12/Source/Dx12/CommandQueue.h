/*
	@file	CommandQueue.h
	@biref	CommandQueueの宣言を記述する
	@author Ishibashi Ryuto
	@date	2018/07/11 初版作成
			2018/07/30 ExecuteCommandLists, Signalを追加
*/
#pragma once
/* システムヘッダインクルード */
#include <memory>
#include <d3d12.h>
#include <wrl.h>
#include <vector>

// ComPtr使用宣言
using Microsoft::WRL::ComPtr;
class Device;
class GraphicsCommandList;

/**
*	@class	CommandQueue
*	@brief	ID3D12CommandQueueのラッパークラス
*
*	コマンドキューのラッパークラス
*	コマンドリストの実行、フェンス等を実装している
*/
class CommandQueue
{
public:
	CommandQueue();
	~CommandQueue();

	/**
	*	@brief		コマンドキューの作成
	*	@param[in]	device	:デバイスのポインタ
	*	@retval		生成成功時	: CommandQueueのshared_ptr
	*	@retval		生成失敗時	: nullptr
	*/
	static std::shared_ptr<CommandQueue> Create(std::shared_ptr<Device> device);

	/**
	*	@brief		コマンドキューの作成
	*	@param[in]	device				: デバイスのポインタ
	*	@param[in]	commandQueueDesc	: コマンドキューの設定項目
	*	@retval 生成成功時	: CommandQueueのshared_ptr
	*	@retval	生成失敗時	: nullptr
	*/
	static std::shared_ptr<CommandQueue> Create(std::shared_ptr<Device> device, const D3D12_COMMAND_QUEUE_DESC& commandQueueDesc);

	/*/
	*	@brief	コマンドキューのComポインタを取得する
	*
	*	@return ID3D12CommandQueueのComPtr
	*/
	ComPtr<ID3D12CommandQueue> GetCommandQueue() const;

	/**
	*	@brief		コマンドを実行する
	*	@param[in]	numCommandLists	:	コマンドリストの個数
	*	@param[in]	ppCommandLists	:	コマンドリスト配列へのポインタ
	*/
	void ExecuteCommandList(UINT numCommandLists, ID3D12CommandList *const *ppCommandLists);

	/**
	*	@brief コマンドを実行する
	*	@param[in] commandList		: コマンドリストクラス
	*/
	void ExecuteCommandList(const std::shared_ptr<GraphicsCommandList> commandList);

	/**
	*	@brief コマンドを実行する
	*	@param[in] commandLists		: コマンドリストクラスの動的配列
	*/
	void ExecuteCommandList(const std::vector<std::shared_ptr<GraphicsCommandList>> & commandLists);

	/**
	*	@brief	コマンドキューの実行を待つ
	*/
	void Signal();

private:
	/* 変数宣言 */
	ComPtr<ID3D12CommandQueue> mCommandQueue;	//! コマンドキューの実体
	UINT mFenceValue;							//! フェンスパラメータ
	ComPtr<ID3D12Fence> mFence;					//! フェンスオブジェクト
	HANDLE mFenceEvent;							//! フェンスイベント
};

