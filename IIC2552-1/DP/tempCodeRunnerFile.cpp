void computing_distances(){
  rep(i, N){
    bfs(dirties[i].first, dirties[i].second);
    rep_(j, i + 1, N){
      dis[i][j] = dis_temp[dirties[i].first][dirties[i].second];
      dis[j][i] = dis_temp[i][j];
    }
  }
}