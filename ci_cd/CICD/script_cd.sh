#!/bin/bash
#
# Путь к приватному SSH ключу
KEY="/home/gitlab-runner/.ssh/id_rsa"

# Имя пользователя и IP-адрес виртуальной машины
USER="ivan"
HOST="192.168.10.211"

# Директория, куда будут скопированы артефакты
DEST_DIR="/usr/local/bin"

# Копирование артефактов на виртуальную машину
scp -i "$KEY" artifacts/* "$USER@$HOST:/tmp/"

if [ $? -eq 0 ]; then
  ssh -i "$KEY" "$USER@$HOST" "sudo mv /tmp/s21_cat /tmp/s21_grep  $DEST_DIR/"

# Проверка статуса операции
  if [ $? -eq 0 ]; then
  	echo "Deployment successful!"
#	curl -s -X POST "https://api.telegram.org/bot7447177813:AAEO0tfMd7gwX1x2VrxjPitwzkLrA50m7H0/sendMessage" -d chat_id="303064959" -d text="Deployment succesful!"
  else
#	curl -s -X POST "https://api.telegram.org/bot7447177813:AAEO0tfMd7gwX1x2VrxjPitwzkLrA50m7H0/sendMessage" -d chat_id="303064959" -d text="Deployment failed!"
  	echo "Deployment failed!!!"
	exit 0 
  fi
  else 
#	curl -s -X POST "https://api.telegram.org/bot7447177813:AAEO0tfMd7gwX1x2VrxjPitwzkLrA50m7H0/sendMessage" -d chat_id="303064959" -d text="Error when copying"
	exit 0
fi

