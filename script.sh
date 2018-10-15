git filter-branch --env-filter \
'export GIT_AUTHOR_NAME="charlchi"
export GIT_COMMITTER_NAME="charlchi"
export GIT_AUTHOR_EMAIL="cmoller@student.wethinkcode.co.za"
export GIT_COMMITTER_EMAIL="cmoller@student.wethinkcode.co.za"
' && rm -fr "$(git rev-parse --git-dir)/refs/original"
