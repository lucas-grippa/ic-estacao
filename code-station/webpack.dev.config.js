const webpack = require('webpack');
const path = require('path');
const ExtractTextPlugin = require('extract-text-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const { spawn } = require('child_process');

// Config directories
const SRC_DIR = path.resolve(__dirname, 'src');
const OUTPUT_DIR = path.resolve(__dirname, 'public');

// Any directories you will be adding code/files into, need to be added to this array so webpack will pick them up
const defaultInclude = [SRC_DIR];

module.exports = {
  entry: './src/index.jsx',
  output: {
    path: __dirname + '/public',
    filename: './app.js'
  },
  resolve: {
    extensions: ['*', '.js', '.jsx'],
    alias: {
      modules: __dirname + '/node_modules',
      jquery: 'modules/admin-lte/plugins/jQuery/jquery-2.2.3.min.js',
      bootstrap: 'modules/admin-lte/bootstrap/js/bootstrap.js'
    }
  },
  module: {
    loaders: [{
      test: /.js[x]?$/,
      loader: 'babel-loader',
      //exclude: /node_modules/,
      //include: defaultInclude,
      query: {
        cacheDirectory: true,
        presets: ['es2015', 'react'],
        plugins: ['transform-object-rest-spread']
      }
    },{
      test: /\.css$/,
      //include: defaultInclude,
      loader: ExtractTextPlugin.extract({
        fallback: "style-loader",
        use: "css-loader"
      })
    },{
      test: /.(png|jpg|jpeg|gif|svg|woff|woff2|eot|ttf)(\?v=\d+\.\d+\.\d+)?$/,
      //include: defaultInclude,
      loader: 'file-loader' 
    }]
  },
  target: 'electron-renderer',
  plugins: [
    new CopyWebpackPlugin([
      {
        from: 'node_modules/monaco-editor/min/vs',
        to: 'vs',
      }
    ]),
    new webpack.ProvidePlugin({
      $: 'jquery',
      jQuery: 'jquery',
      'window.jQuery': 'jquery' 
    }),
    new ExtractTextPlugin('app.css'),
    new webpack.DefinePlugin({
      'process.env.NODE_ENV': JSON.stringify('development')
    })
  ],
  devtool: 'cheap-source-map',
  devServer: {
    contentBase: './public',
    stats: {
      colors: true,
      chunks: false,
      children: false
    },
    setup() {
      spawn(
        'electron',
        ['.'],
        { shell: true, env: process.env, stdio: 'inherit' }
      )
      .on('close', code => process.exit(0))
      .on('error', spawnError => console.error(spawnError));
    }
  }
};
