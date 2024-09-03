#!/bin/bash

# コピー元の.gitignoreファイルのパス
SOURCE_FILE=".gitignore"

# 連番ディレクトリに対してコピーを実行
for i in $(seq -w 0 9); do
  DEST_DIR="$i"
  if [ -d "0$DEST_DIR" ]; then
    cp "$SOURCE_FILE" "./0$DEST_DIR/"
    echo "Copied $SOURCE_FILE to 0$DEST_DIR/"
  else
    echo "Directory 0$DEST_DIR does not exist."
  fi
done