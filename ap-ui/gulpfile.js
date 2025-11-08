// 1. install nodejs
// 2. npm i
// 3. gulp

const fs = require('fs');
const gulp = require('gulp');
const htmlmin = require('gulp-htmlmin');
const cleancss = require('gulp-clean-css');
const uglify = require('gulp-uglify');
const gzip = require('gulp-gzip');
const del = require('del');
const inline = require('gulp-inline');
const inlineImages = require('gulp-css-base64');
const favicon = require('gulp-base64-favicon');

const dataFolder = 'preprocessed/';

function clean() {
    del([ dataFolder + '*']);
    return Promise.resolve(true);
}

function buildfs_embeded() {
    var source = dataFolder + 'index.html.gz';
    var destination = dataFolder + 'index.html.gz.h';
    
    var wstream = fs.createWriteStream(destination);
    wstream.on('error', function (err) {
        console.log("buildfs_embeded err", err);
    });

    var data = fs.readFileSync(source);

    wstream.write('#define index_html_gz_len ' + data.length + '\n');
    wstream.write('const char index_html_gz[] PROGMEM = {')

    for (i=0; i<data.length; i++) {
        if (i % 1000 == 0) wstream.write("\n");
        wstream.write('0x' + ('00' + data[i].toString(16)).slice(-2));
        if (i<data.length-1) wstream.write(',');
    }

    wstream.write('\n};')
    wstream.end();

    del([source]);
    return Promise.resolve(true);
}

function buildfs_inline() {
    return gulp.src('public/*.html')
        //.pipe(favicon())
        .pipe(inline({
            base: 'public/',
            js: uglify,
            css: [cleancss, inlineImages],
            disabledTypes: ['svg', 'img']
        }))
        .pipe(htmlmin({
            collapseWhitespace: true,
            removecomments: true,
            aside: true,
            minifyCSS: true,
            minifyJS: true
        }))
        .pipe(gzip())
        .pipe(gulp.dest(dataFolder));
}

gulp.task(clean);
gulp.task(buildfs_embeded);
gulp.task(buildfs_inline);

gulp.task('default', gulp.series(clean, buildfs_inline, buildfs_embeded));