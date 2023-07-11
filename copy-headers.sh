npm i -g node-addon-api
sudo cp -r /home/amirmuha/.nvm/versions/node/$(node -v)/include/node /usr/include
sudo mkdir -p /usr/include/napi
sudo cp -r /home/amirmuha/.nvm/versions/node/$(node -v)/lib/node_modules/node-addon-api/* /usr/include/napi
