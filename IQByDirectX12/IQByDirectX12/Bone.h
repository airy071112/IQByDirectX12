/*
	Bone.h
	ボーン情報を格納するクラス
	@author Ishibashi Ryuto
	@date 
	2018/09/11	初版作成
*/
#pragma once
// システムヘッダインクルード

// 自作ヘッダインクルード
#include "Math/Math.h"

class Bone
{
public:
	/// コンストラクタ
	Bone(const Math::Vector3 & headPosition);

	/// デストラクタ
	~Bone();

	/// ボーンの回転を設定する
	void SetRotation(const Math::Quaternion& rotation);
	void SetRotation(const Math::Vector3& rotation);
	void SetRotation(float rotX, float rotY, float rotZ);

	/// ボーンを回転させる
	void Rotate(const Math::Matrix4x4& matrix);

	/// ボーンの回転情報を取得する
	const Math::Quaternion& GetRotation() const;

	/// ボーン回転行列を取得する
	const Math::Matrix4x4 GetBoneMatrix() const;
private:
	Math::Vector3 mOriginHeadPosition;		// ボーン初期ヘッド位置
	Math::Vector3 mRotatedHeadPosition;		// 回転操作後のボーンヘッド位置
	Math::Quaternion mRotation;				// ボーンの回転量
};

