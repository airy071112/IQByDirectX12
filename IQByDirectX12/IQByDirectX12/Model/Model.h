/*
	Model.h
	ゲーム内のモデル毎に扱う情報の管理と描画等を行う
	@author Ishibashi Ryuto
	@date
	2018/09/03	初版作成
*/
#pragma once
// システムヘッダインクルード
#include <memory>

// 自作ヘッダインクルード
#include "../Math/Math.h"

// クラス使用宣言
class ModelDataManager;

class Model
{
public:
	/// コンストラクタ
	Model();
	Model(int modelHandle);

	/// デストラクタ
	~Model();

	/// @fn Create
	/// モデルクラスを生成する
	/// @note Modelクラスの実体はこのメソッドでのみ生成可能
	/// @param[in] modelHandle	: モデルハンドル
	/// @retval モデルのスマートポインタ
	std::shared_ptr<Model> Create(int modelHandle);

	/// @fn SetPosition
	/// 位置を指定する
	/// @param[in] position : モデル配置位置
	void SetPosition(const Math::Vector3& position);

	/// @fn SetRotation
	/// モデルの回転を指定する
	/// @param[in] rotation : 各軸回転角度
	void SetRotation(const Math::Vector3& rotation);

	/// @fn SetRotation
	/// モデルの回転を指定する
	/// @param[in] rotQuaternion : 各軸回転角度(quaternion)
	void SetRotation(const Math::Quaternion& rotQuaternion);

	/// @fn SetScale
	/// モデルの拡縮率を指定する
	/// @param scale : モデルスケール
	void SetScale(const Math::Vector3& scale);

	/// @fn Draw
	/// モデルの描画処理を行う
	void Draw() const;

private:
	// 変数宣言
	Math::Vector3		mPosition;		// 位置
	Math::Quaternion	mRotation;		// 回転
	Math::Vector3		mScale;			// 拡縮
	Math::Matrix4x4		mModelMatrix;	// モデル行列
	int					mModelHandle;	// モデルハンドル

	// ローカルメソッド定義
	/// @fn CalcModelMatrix
	/// 現在の位置、回転、拡縮からモデル行列を計算する
	void CalcModelMatrix();
};

