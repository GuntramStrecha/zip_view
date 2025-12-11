window.BENCHMARK_DATA = {
  "lastUpdate": 1765472262719,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0da400dc7dae9a77d4758064ae1bb669d096408c",
          "message": "fixup! Add benchmarks to github actions",
          "timestamp": "2025-12-11T17:55:34+01:00",
          "tree_id": "b7283276692604ec67c793bcbbef41df30ad78aa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0da400dc7dae9a77d4758064ae1bb669d096408c"
        },
        "date": 1765472261786,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 138.197,
            "range": "± 23.5564",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 138.731,
            "range": "± 22.4183",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 578.167,
            "range": "± 60.8681",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 566.845,
            "range": "± 73.5245",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 144.633,
            "range": "± 19.8292",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 151.628,
            "range": "± 21.8796",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 157.512,
            "range": "± 20.5731",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 141.232,
            "range": "± 22.9613",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}
