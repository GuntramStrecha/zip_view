window.BENCHMARK_DATA = {
  "lastUpdate": 1765743772512,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark (ARM64)": [
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
          "id": "7444114e0d708342d33f29966494b22b0570c40d",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T18:58:06+01:00",
          "tree_id": "1565a65a55732830ff7703be2d557929b207ea23",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/7444114e0d708342d33f29966494b22b0570c40d"
        },
        "date": 1765735236517,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 150.526,
            "range": "± 8.96692",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 151.259,
            "range": "± 9.89913",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 256.584,
            "range": "± 35.7509",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 254.426,
            "range": "± 30.4416",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.5423,
            "range": "± 0.744213",
            "unit": "ns",
            "extra": "100 samples\n505 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 49.1132,
            "range": "± 0.830042",
            "unit": "ns",
            "extra": "100 samples\n644 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.012,
            "range": "± 1.11376",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.8887,
            "range": "± 380.468",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 92.8557,
            "range": "± 4.77241",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 29.6519,
            "range": "± 2.45142",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 70.0106,
            "range": "± 4.08911",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 65.268,
            "range": "± 10.7263",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 157.208,
            "range": "± 21.7893",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 414.221,
            "range": "± 28.088",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 66.6503,
            "range": "± 1.80445",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.8042,
            "range": "± 2.06126",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 61.1335,
            "range": "± 1.912",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 61.0856,
            "range": "± 1.99951",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.208,
            "range": "± 11.2834",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 151.307,
            "range": "± 11.0034",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.789,
            "range": "± 2.48546",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.62,
            "range": "± 2.91125",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
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
          "id": "5900b5935264621bb7b7b332e48f842a5da935c9",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T21:20:19+01:00",
          "tree_id": "d09077e0ded4cc83602fec81e0a6c0aa43887319",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/5900b5935264621bb7b7b332e48f842a5da935c9"
        },
        "date": 1765743771712,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 150.929,
            "range": "± 6.11151",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 151.261,
            "range": "± 8.18448",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 228.489,
            "range": "± 24.7123",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 221.165,
            "range": "± 23.4735",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.5325,
            "range": "± 1.10706",
            "unit": "ns",
            "extra": "100 samples\n503 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 48.8323,
            "range": "± 0.51688",
            "unit": "ns",
            "extra": "100 samples\n645 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.0933,
            "range": "± 1.26989",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.8675,
            "range": "± 152.351",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 92.0095,
            "range": "± 2.72113",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 29.4595,
            "range": "± 2.0655",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 48.833,
            "range": "± 2.41348",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 56.2352,
            "range": "± 4.80819",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 157.495,
            "range": "± 14.8241",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 414.875,
            "range": "± 23.0061",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 65.8363,
            "range": "± 1.29081",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.0058,
            "range": "± 1.29181",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 60.5339,
            "range": "± 1.1747",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.7197,
            "range": "± 1.90396",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.776,
            "range": "± 6.72557",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 152.785,
            "range": "± 10.196",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.704,
            "range": "± 2.43562",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.199,
            "range": "± 2.33506",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}