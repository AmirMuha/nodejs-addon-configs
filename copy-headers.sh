NODE_VERSION= node -v
echo $NODE_VERSION
npm i -g node-addon-api
sudo cp -r /home/amirmuha/.nvm/versions/node/$NODE_VERSION/include/node /usr/include
sudo mkdir -p /usr/include/napi
sudo cp -r /home/amirmuha/.nvm/versions/node/$NODE_VERSION/lib/node_modules/node-addon-api/**/* /usr/include/napi
